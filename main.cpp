#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "sorts.h"

bool ascending(int a, int b) { return a > b; }
bool descending(int a, int b) { return a < b; }

std::vector<int> generate_test_data(size_t size) {
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-1000, 1000);
    
    for (auto& num : data) {
        num = distrib(gen);
    }
    return data;
}

void print_array(const int* ar, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << ar[i] << " ";
    }
    std::cout << "\n\n";
}

void test_sort(const std::string& name, 
              void (*sort_func)(int*, size_t, bool (*)(int, int)), 
              bool comp(int, int),
              const std::vector<int>& test_data) {
    
    std::vector<int> data(test_data);
    int* arr = data.data();
    size_t size = data.size();

    std::cout << "Testing " << name << ":\n";
    std::cout << "Original: ";
    print_array(arr, size);

    sort_func(arr, size, comp);
    
    std::cout << "Sorted: ";
    print_array(arr, size);
}

int main() {
    const size_t test_size = 15;
    auto data = generate_test_data(test_size);
    
    test_sort("BubbleSort", BubbleSort, ascending, data);
    test_sort("InsertionSort", InsertionSort, ascending, data);
    test_sort("SelectionSort", SelectionSort, ascending, data);
    test_sort("ShellSort", ShellSort, ascending, data);
    test_sort("CountSort", CountSort, ascending, data);
    test_sort("QuickSort", QuickSort, ascending, data);
    test_sort("QuickSortMod", QuickSortMod, ascending, data);
    test_sort("MergeSort", MergeSort, ascending, data);
    test_sort("Heapsort", Heapsort, ascending, data);

    std::cout << "\n\nTesting descending order:\n";
    test_sort("QuickSort (descending)", QuickSort, descending, data);

    return 0;
}









