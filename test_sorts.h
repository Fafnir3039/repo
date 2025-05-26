#ifndef TEST_SORTS_H
#define TEST_SORTS_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "sorts.h"

//bool ascending(int a, int b) { return a > b; }
//bool descending(int a, int b) { return a < b; }

std::vector<int> generate_test_data(size_t size);

void print_array(const int* ar, size_t size);

void test_sort(const std::string& name, 
              void (*sort_func)(int*, size_t, bool (*)(int, int)), 
              bool comp(int, int),
              const std::vector<int>& test_data);

int test_sort_time(const std::string& name,
                    void (*sort_func)(int*, size_t, bool (*)(int, int)),
                    bool comp(int, int),
                    const std::vector<int>& test_data);

#endif // TEST_SORTS_H
