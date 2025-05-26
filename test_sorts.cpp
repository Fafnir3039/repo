#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include "sorts.h"

using namespace std;

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
    
    std::vector<int> arr(test_data);

    std::cout << "Testing " << name << ":\n";
    std::cout << "Original: ";
    print_array(test_data.data(), test_data.size());

    sort_func(arr.data(), arr.size(), comp);
    
    std::cout << "Sorted: ";
    print_array(arr.data(), arr.size());

    std::vector<int> expected = test_data;
    std::sort(expected.begin(), expected.end());

    std::cout << ((arr == expected) ? "PASS" : "FAIL") << " " << name << "\n\n\n" << std::endl;

}

int test_sort_time(const std::string& name,
               void (*sort_func)(int*, size_t, bool (*)(int, int)),
               bool comp(int, int),
               const std::vector<int>& test_data) {

    std::vector<int> arr(test_data);
    auto start_time = std::chrono::steady_clock::now();
    sort_func(arr.data(), arr.size(), comp);
    auto end_time = std::chrono::steady_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
}
