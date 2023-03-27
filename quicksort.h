#pragma once
#include<vector>

#define BUILD_GRAPHICS

int partition(int* array, int left, int right, int& comparasions, int& swaps);
int median_partition(int*, int, int, int&, int&);
std::vector<int> three_pivot_partition(int* array, int left, int right, int& comparasions, int& swaps);

void quick_sort(int* array, int left, int right, int& comparasions, int& swaps);
void median3_quick_sort(int* array, int left, int right, int& comparasions, int& swaps);
void three_pivot_quick_sort(int* array, int left, int right, int& comparasions, int& swaps);