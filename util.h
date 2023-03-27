#pragma once
#include<iostream>

constexpr auto DEFAULT_PATH = "./examples/";

void swap(int& a, int& b);

void change_array(int* array, int left, int right);
int median_of_three(int* array, int left, int right);
void insertion_sort(int* arr, int left, int right, int& comparasions, int& swaps);
bool read_filename(int argc, char** argv, std::string& filename);
void help();
void print_array(int* array, size_t size);
void print_array(float* array, size_t size);

std::unique_ptr<int[]> generate_worst_array(size_t size);
std::unique_ptr<int[]> generate_best_array(size_t size);
std::unique_ptr<int[]> generate_avarage_array(size_t size);
