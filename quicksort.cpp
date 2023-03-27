#include "quicksort.h"
#include "util.h"
#include<vector>
#include<algorithm>


int partition(int* array, int left, int right, int& comparasions, int& swaps) {
	int pivot = array[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		comparasions++;
		if (array[j] <= pivot) {
			i++;
			swaps++;
			swap(array[i], array[j]);
		}
	}
	swaps++;
	swap(array[i + 1], array[right]);
	return i + 1;
}

void quick_sort(int* array, int left, int right, int& comparasions, int& swaps) {
	if (left < right) {
		int split_index = partition(array, left, right, comparasions, swaps);
		quick_sort(array, left, split_index - 1, comparasions, swaps);
		quick_sort(array, split_index + 1, right, comparasions, swaps);
	}
}

int median_partition(int* array, int left, int right, int& comparasions, int& swaps) {

	int pivot_index = median_of_three(array, left, right);
	swaps++;
	swap(array[pivot_index], array[right]);
	int pivot = array[right], i = left - 1;
	for (size_t j = left; j < right; j++) {
		comparasions++;
		if (array[j] <= pivot) {
			i++;
			swaps++;
			swap(array[i], array[j]);
		}
	}

	swaps++;
	swap(array[i + 1], array[right]);

	return i + 1;
}

void median3_quick_sort(int* array, int left, int right, int& comparasions, int& swaps) {
	
	if (right - left > 2) {
		int pivot = median_partition(array, left, right, comparasions, swaps);
		median3_quick_sort(array, left, pivot - 1, comparasions, swaps);
		median3_quick_sort(array, pivot + 1, right, comparasions, swaps);
	}
	else {
		insertion_sort(array, left, right, comparasions, swaps);
	}
}

std::vector<int> three_pivot_partition(int* array, int left, int right, int& comparasions, int& swaps) {
	int a = left + 2;
	int b = left + 2;
	int c = right - 1;
	int d = right - 1;

	int p = array[left];
	int q = array[left + 1];
	int r = array[right];

	while (b <= c) {
		while (array[b] < q && b <= c) {
			comparasions += 2;
			if (array[b] < p) {
				swaps++;
				swap(array[a], array[b]);
				a++;
			}

			b++;
		}
		comparasions++;
		while (array[c] > q && b <= c) {
			comparasions += 2;
			if (array[c] > r) {
				swaps++;
				swap(array[c], array[d]);
				d--;
			}
			c--;
		}
		comparasions++;
		if (b <= c) {
			comparasions++;
			if (array[b] > r) {
				comparasions++;
				if (array[c] < p) {
					swaps += 2;
					swap(array[a], array[b]), swap(array[a], array[c]);
					a++;
				}
				else {
					swaps++;
					swap(array[b], array[c]);
				}
				swaps++;
				swap(array[c], array[d]);
				b++;
				c--;
				d--;
			}
			else {
				comparasions++;
				if (array[c] < p) {
					swaps += 2;
					swap(array[a], array[b]), swap(array[a], array[c]);
					a++;
				}
				else {
					swaps++;
					swap(array[b], array[c]);
				}
				b++;
				c--;
			}
		}
	}
	
	a--, b--, c++, d++;
	swaps += 2;
	swap(array[left + 1], array[a]), swap(array[a], array[b]);
	a--;
	swaps += 2;
	swap(array[left], array[a]), swap(array[right], array[d]);

	return std::vector<int>{a, b, d};

}

void three_pivot_quick_sort(int* array, int left, int right, int& comparasions, int& swaps) {
	if (right - left > 2) {
		change_array(array, left, right);
		std::vector<int> partition = three_pivot_partition(array, left, right, comparasions, swaps);
		three_pivot_quick_sort(array, left, partition[0] - 1, comparasions, swaps);
		three_pivot_quick_sort(array, partition[0] + 1, partition[1] - 1, comparasions, swaps);
		three_pivot_quick_sort(array, partition[1] + 1, partition[2] - 1, comparasions, swaps);
		three_pivot_quick_sort(array, partition[2] + 1, right, comparasions, swaps);
	}
	else {
		insertion_sort(array, left, right, comparasions, swaps);
	}
}