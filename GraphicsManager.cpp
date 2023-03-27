#include "GraphicsManager.h"
#include "quicksort.h"
#include "filemanager.h"
#include<fstream>
#include<chrono>

GraphicsManager::GraphicsManager(size_t size): _size(size) {
	_q_sort_comp_array = std::make_unique<int[]>(size);
	_median_comp_array = std::make_unique<int[]>(size);
	_three_p_comp_array = std::make_unique<int[]>(size);
	sizes = std::make_unique<int[]>(size);
}

void GraphicsManager::build_graph(const MODE mode) throw(FileManager::FileNotFoundException) {
	int index = 0;
	for (int i = 1; i <= _size; i++) {
		int comparasions = 0, swaps = 0;

		// Quicksort
		std::unique_ptr<int[]> first = _builders[mode](i);
		quick_sort(first.get(), 0, i - 1, comparasions, swaps);
		_q_sort_comp_array[index] = comparasions + swaps;

		comparasions = 0, swaps = 0;

		// Median of 3 quicksort
		std::unique_ptr<int[]> second = _builders[mode](i);
		median3_quick_sort(second.get(), 0, i - 1, comparasions, swaps);
		_median_comp_array[index] = comparasions + swaps;


		// Three Pivot quicksort
		std::unique_ptr<int[]> third = _builders[mode](i);
		three_pivot_quick_sort(third.get(), 0, i - 1, comparasions, swaps);
		_three_p_comp_array[index] = comparasions + swaps;

		sizes[index] = i;
		index++;
	}

	std::ofstream out("comps.dat", std::ios::binary);
	if (!out.is_open()) throw FileManager::FileNotFoundException();

	out.write((char*)&_size, sizeof(_size));
	out.write((char*)sizes.get(), sizeof(int) * _size);
	out.write((char*)_q_sort_comp_array.get(), sizeof(int) * _size);
	out.write((char*)_median_comp_array.get(), sizeof(int) * _size);
	out.write((char*)_three_p_comp_array.get(), sizeof(int) * _size);

	out.close();

	system("python3 sorting_algorithms.py worst_case.dat");
}