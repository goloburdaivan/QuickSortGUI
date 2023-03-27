#include "util.h"
#include "quicksort.h"
#include<memory>

void swap(int& a, int& b) {
    int temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

void change_array(int* array, int left, int right) {
    if (array[left] > array[left + 1]) swap(array[left], array[left + 1]);
    if (array[left] > array[right]) swap(array[left], array[right]);
    if (array[left + 1] > array[right]) swap(array[left + 1], array[right]);
}

int median_of_three(int* array, int left, int right) {
    int mid = (left + right) / 2;
    if ((array[left] < array[mid] && array[mid] < array[right]) || (array[right] < array[mid] && array[mid] < array[left])) {
        return mid;
    }
    if ((array[left] < array[right] && array[right] < array[mid]) || (array[mid] < array[right] && array[right] < array[left])) {
        return right;
    }
    return left;
}

void insertion_sort(int* array, int left, int right, int& comparasions, int& swaps) {
    for (int i = left + 1; i < right + 1; i++) {
        int j = i - 1;
        int key = array[i];
        while (j >= 0 && array[j] > key) {
            comparasions++;
            swaps++;
            array[j + 1] = array[j];
            j--;
        }
        if (j != left - 1) comparasions++;
        array[j + 1] = key;
    }
}

void insertion_sort_operations(int* array, int left, int right, int& operations) {
    for (int i = left + 1; i < right + 1; i++) {
        int j = i - 1;
        int key = array[i];
        while (j >= 0 && array[j] > key) {
            operations += 2;
            array[j + 1] = array[j];
            j--;
        }
        if (j != left - 1) operations++;
        array[j + 1] = key;
    }
}

void help() {
    std::cout << "[HELP] Usage: SortingAlgos [filename]" << std::endl;
}

bool read_filename(int argc, char** argv, std::string& filename) {
    if (argc < 2) {
        return false;
    }

    if (strcmp(argv[1], "--help") == 0) {
        help();
        return false;
    }

    filename = argv[1];

    return true;
}

void print_array(int* array, size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}
void print_array(float* array, size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

std::unique_ptr<int[]> generate_worst_array(size_t size) {
    std::unique_ptr<int[]> array = std::make_unique<int[]>(size);

    int value = 0;
    for (int i = 0; i < size; i++) {
        array[i] = value++;
    }

    return array;
}

std::unique_ptr<int[]> generate_best_array(size_t size) {
    std::unique_ptr<int[]> array = std::make_unique<int[]>(size);
    int value = 0;
    for (size_t i = 0; i < size; i++) {
        array[i] = value++;
    }

    return array;
}

std::unique_ptr<int[]> generate_avarage_array(size_t size) {
    srand(time(NULL));
    std::unique_ptr<int[]> array = std::make_unique<int[]>(size);
    for (size_t i = 0; i < size; i++) {
        array[i] = -1000 + rand() % 1000;
    }

    return array;
}