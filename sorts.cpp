#include "sorts.h"
#include <algorithm>
#include <vector>
#include <cmath>

bool less(int a, int b) { return a < b; }
bool greater(int a, int b) { return a > b; }

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int)) {
    for (size_t i = 0; i < size-1; i++) {
        for (size_t j = 0; j < size-i-1; j++) {
            if (comp(ar[j+1], ar[j])) {
                swap(ar[j], ar[j+1]);
            }
        }
    }
}

void InsertionSort(int* ar, size_t size, bool (*comp)(int, int)) {
    for (size_t i = 1; i < size; i++) {
        int key = ar[i];
        size_t j = i;
        while (j > 0 && comp(key, ar[j-1])) {
            ar[j] = ar[j-1];
            j--;
        }
        ar[j] = key;
    }
}

void SelectionSort(int* ar, size_t size, bool (*comp)(int, int)) {
    for (size_t i = 0; i < size-1; i++) {
        size_t min_idx = i;
        for (size_t j = i+1; j < size; j++) {
            if (comp(ar[j], ar[min_idx])) {
                min_idx = j;
            }
        }
        swap(ar[i], ar[min_idx]);
    }
}

void ShellSort(int* ar, size_t size, bool (*comp)(int, int)) {
    for (size_t gap = size/2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < size; i++) {
            int temp = ar[i];
            size_t j;
            for (j = i; j >= gap && comp(temp, ar[j-gap]); j -= gap) {
                ar[j] = ar[j-gap];
            }
            ar[j] = temp;
        }
    }
}

void CountSort(int* ar, size_t size, bool (*comp)(int, int)) {
    if (size == 0) return;
    
    int max = findMax(ar, size);
    int min = findMin(ar, size);
    int range = max - min + 1;
    
    std::vector<int> count(range), output(size);
    
    for (size_t i = 0; i < size; i++)
        count[ar[i]-min]++;
    
    for (int i = 1; i < range; i++)
        count[i] += count[i-1];
    
    for (int i = size-1; i >= 0; i--) {
        output[count[ar[i]-min]-1] = ar[i];
        count[ar[i]-min]--;
    }
    
    for (size_t i = 0; i < size; i++)
        ar[i] = output[i];
        
    if (comp == greater) {
        for (size_t i = 0; i < size/2; i++) {
            swap(ar[i], ar[size-i-1]);
        }
    }
}

void quickSortHelper(int* ar, size_t left, size_t right, bool (*comp)(int, int)) {
    if (left < right) {
        size_t pivot = left;
        for (size_t i = left + 1; i <= right; i++) {
            if (comp(ar[i], ar[left])) {
                pivot++;
                swap(ar[i], ar[pivot]);
            }
        }
        swap(ar[left], ar[pivot]);
        
        if (pivot > 0) quickSortHelper(ar, left, pivot-1, comp);
        quickSortHelper(ar, pivot+1, right, comp);
    }
}

void QuickSort(int* ar, size_t size, bool (*comp)(int, int)) {
    if (size <= 1) return;
    quickSortHelper(ar, 0, size-1, comp);
}

void quickSortModHelper(int* ar, size_t left, size_t right, bool (*comp)(int, int)) {
    if (right - left < 10) {

        for (size_t i = left+1; i <= right; i++) {
            int key = ar[i];
            size_t j = i;
            while (j > left && comp(key, ar[j-1])) {
                ar[j] = ar[j-1];
                j--;
            }
            ar[j] = key;
        }
    } else if (left < right) {
        size_t pivot = left;
        for (size_t i = left + 1; i <= right; i++) {
            if (comp(ar[i], ar[left])) {
                pivot++;
                swap(ar[i], ar[pivot]);
            }
        }
        swap(ar[left], ar[pivot]);
        
        if (pivot > 0) quickSortModHelper(ar, left, pivot-1, comp);
        quickSortModHelper(ar, pivot+1, right, comp);
    }
}
void QuickSortMod(int* ar, size_t size, bool (*comp)(int, int)) {
    if (size <= 1) return;
    quickSortModHelper(ar, 0, size-1, comp);
}

void merge(int* ar, size_t left, size_t mid, size_t right, bool (*comp)(int, int)) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    
    std::vector<int> L(n1), R(n2);
    
    for (size_t i = 0; i < n1; i++)
        L[i] = ar[left + i];
    for (size_t j = 0; j < n2; j++)
        R[j] = ar[mid + 1 + j];
    
    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])) {
            ar[k] = L[i];
            i++;
        } else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        ar[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        ar[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(int* ar, size_t left, size_t right, bool (*comp)(int, int)) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSortHelper(ar, left, mid, comp);
        mergeSortHelper(ar, mid+1, right, comp);
        merge(ar, left, mid, right, comp);
    }
}

void MergeSort(int* ar, size_t size, bool (*comp)(int, int)) {
    if (size <= 1) return;
    mergeSortHelper(ar, 0, size-1, comp);
}

void heapify(int* ar, size_t size, size_t root, bool (*comp)(int, int)) {
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;
    
    if (left < size && comp(ar[left], ar[largest]))
        largest = left;
    
    if (right < size && comp(ar[right], ar[largest]))
        largest = right;
    
    if (largest != root) {
        swap(ar[root], ar[largest]);
        heapify(ar, size, largest, comp);
    }
}

void Heapsort(int* ar, size_t size, bool (*comp)(int, int)) {

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(ar, size, i, comp);
    
    for (int i = size - 1; i >= 0; i--) {
        swap(ar[0], ar[i]);
        heapify(ar, i, 0, comp);
    }
    
    if (comp == greater) {
        for (size_t i = 0; i < size/2; i++) {
            swap(ar[i], ar[size-i-1]);
        }
    }
}

void RadixSort(int* ar, size_t size, bool (*comp)(int, int)) {
    if (size == 0) return;
    
    int max = findMax(ar, size);
    for (int exp = 1; max/exp > 0; exp *= 10) {
        std::vector<int> output(size);
        std::vector<int> count(10, 0);
        
        for (size_t i = 0; i < size; i++)
            count[(ar[i]/exp) % 10]++;
        
        for (int i = 1; i < 10; i++)
            count[i] += count[i-1];
        
        for (int i = size-1; i >= 0; i--) {
            output[count[(ar[i]/exp) % 10] - 1] = ar[i];
            count[(ar[i]/exp) % 10]--;
        }
        
        for (size_t i = 0; i < size; i++)
            ar[i] = output[i];
    }

    if (comp == greater) {
        for (size_t i = 0; i < size/2; i++) {
            swap(ar[i], ar[size-i-1]);
        }
    }
}

const int RUN = 32;

void insertionSortForTim(int* ar, size_t left, size_t right, bool (*comp)(int, int)) {
    for (size_t i = left+1; i <= right; i++) {
        int temp = ar[i];
        size_t j = i;
        while (j > left && comp(temp, ar[j-1])) {
            ar[j] = ar[j-1];
            j--;
        }
        ar[j] = temp;
    }
}

void TimSort(int* ar, size_t size, bool (*comp)(int, int)) {
    for (size_t i = 0; i < size; i += RUN)
        insertionSortForTim(ar, i, std::min(i+RUN-1, size-1), comp);
    
    for (size_t mergeSize = RUN; mergeSize < size; mergeSize *= 2) {

for (size_t left = 0; left < size; left += 2*mergeSize) {
            size_t mid = left + mergeSize - 1;
            size_t right = std::min(left + 2*mergeSize - 1, size-1);
            if (mid < right)
                merge(ar, left, mid, right, comp);
        }
    }
}

int findMax(int* ar, size_t size) {
    int max = ar[0];
    for (size_t i = 1; i < size; i++)
        if (ar[i] > max) max = ar[i];
    return max;
}

int findMin(int* ar, size_t size) {
    int min = ar[0];
    for (size_t i = 1; i < size; i++)
        if (ar[i] < min) min = ar[i];
    return min;
}