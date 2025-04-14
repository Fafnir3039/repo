#ifndef SORTS_H
#define SORTS_H

#include <cstddef> // for size_t

bool less(int a, int b);
bool greater(int a, int b);

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int));
void InsertionSort(int* ar, size_t size, bool (*comp)(int, int));
void SelectionSort(int* ar, size_t size, bool (*comp)(int, int));
void ShellSort(int* ar, size_t size, bool (*comp)(int, int));
void CountSort(int* ar, size_t size, bool (*comp)(int, int));
void QuickSort(int* ar, size_t size, bool (*comp)(int, int));
void QuickSortMod(int* ar, size_t size, bool (*comp)(int, int));
void MergeSort(int* ar, size_t size, bool (*comp)(int, int));
void Heapsort(int* ar, size_t size, bool (*comp)(int, int));

void RadixSort(int* ar, size_t size, bool (*comp)(int, int));
void TimSort(int* ar, size_t size, bool (*comp)(int, int));

void swap(int& a, int& b);
int findMax(int* ar, size_t size);
int findMin(int* ar, size_t size);
void heapify(int* ar, size_t size, size_t root, bool (*comp)(int, int));
void merge(int* ar, size_t left, size_t mid, size_t right, bool (*comp)(int, int));
void quickSortHelper(int* ar, size_t left, size_t right, bool (*comp)(int, int));
void quickSortModHelper(int* ar, size_t left, size_t right, bool (*comp)(int, int));

#endif // SORTS_H