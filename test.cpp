#include <fstream>
#include "sorts.h"
#include "test_sorts.h"

bool ascending(int a, int b) { return a > b; }
bool descending(int a, int b) { return a < b; }

/*
• на 100 до размера массива1`000
• на 500 до размера массива 10`000
• на 1000 до — 100`000
• на 2500 до — 200`000
• на 10000 до — 1`000`000
*/

int next_test_size(int current) {
    if (current >= 200000) return current + 10000;
    if (current >= 100000) return current + 2500;
    if (current >= 10000) return current + 1000;
    if (current >= 1000) return current + 500;
    return current + 100;
}

int main() {


    size_t test_size = 15;
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

    size_t test_sizes = 100;

    std::fstream file;
    file.open("example.txt", std::ios::out | std::ios::trunc);


    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    file << "N\tBubbleSort\tInsertionSort\tSelectionSort\tShellSort\tCountSort\tQuickSort\tQuickSortMod\tMergeSort\tHeapsort\n";
    while (test_sizes <= 10000) {
        auto data = generate_test_data(test_sizes);
        file << test_size << "\t\t";
        file << test_sort_time("BubbleSort", BubbleSort, ascending, data) << "\t\t";
        file << test_sort_time("InsertionSort", InsertionSort, ascending, data) << "\t\t";
        file << test_sort_time("SelectionSort", SelectionSort, ascending, data) << "\t\t";
        file << test_sort_time("ShellSort", ShellSort, ascending, data) << "\t\t";
        file << test_sort_time("CountSort", CountSort, ascending, data) << "\t\t";
        file << test_sort_time("QuickSort", QuickSort, ascending, data) << "\t\t";
        file << test_sort_time("QuickSortMod", QuickSortMod, ascending, data) << "\t\t";
        file << test_sort_time("MergeSort", MergeSort, ascending, data) << "\t\t";
        file << test_sort_time("Heapsort", Heapsort, ascending, data) << "\t\t";
        file << std::endl;

        test_sizes = next_test_size(test_sizes);
    }
    return 0;
}
