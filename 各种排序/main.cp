//
//  main.cpp
//  draft
//
//  Created by 邱兆丰 on 2020/1/3.
//  Copyright © 2020 菇生. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <bitset>
#include <climits>
#include <cmath>
#include <time.h>
#include <algorithm>

using namespace std;

template <class Type>
class MySorts {
private:
    // No Sonstruct is allowed
    MySorts();
    
    static int partition(vector<Type> & arr, int lhs, int rhs) {
        // Compared with base every time;
        int baseVal = arr[lhs];
        while (lhs < rhs) {
            while (lhs < rhs && baseVal <= arr[rhs]) {
                rhs--;
            }
            arr[lhs] = arr[rhs];
            while (lhs < rhs && arr[lhs] <= baseVal) {
                lhs++;
            }
            arr[rhs] = arr[lhs];
        }
        // At the end, lhs should be equal to rhs set back the base.
        // It is ok to return whatever lhs or rhs.
        arr[lhs] = baseVal;
        return lhs;
    }
    
    static void reQuickSort2(vector<Type> & arr, int lhs, int rhs) {
        if (lhs < rhs) {
            int basePos = partition(arr, lhs, rhs);
            reQuickSort2(arr, lhs, basePos - 1);
            reQuickSort2(arr, basePos + 1, rhs);
        }
    }
    
    static void buildHeap(vector<Type> & arr) {
        int lastParent = (arr.size() - 1) / 2;
        for (int i = lastParent; i >= 0; i--) {
            heapify(arr, arr.size(), i);
        }
    }
    
    static void heapify(vector<int> & arr, int n, int index) {
        int c1 = index * 2 + 1;
        int c2 = index * 2 + 2;
        int max = index;
        if (c1 < n) {
            max = arr[c1] > arr[max] ? c1 : max;
        }
        if (c2 < n) {
            max = arr[c2] > arr[max] ? c2 : max;
        }
        if (max != index) {
            swap(arr[index], arr[max]);
            heapify(arr, n, max);
        }
    }
    
    static Type median3(vector<Type> & arr, int lhs, int rhs) {
        // Let arr[lhs] < arr[center] < arr[rhs]
        int center = (lhs + rhs) / 2;
        if (arr[lhs] > arr[center]) {
            swap(arr[lhs], arr[center]);
        }
        if (arr[center] > arr[rhs]) {
            swap(arr[center], arr[rhs]);
        }
        if (arr[lhs] > arr[center]) {
            swap(arr[lhs], arr[center]);
        }
        // move pivot to arr[rhs - 1]
        swap(arr[center], arr[rhs - 1]);
        // so that we only have to consider arr[lhs + 1] to arr[rhs - 2]
        return arr[rhs - 1];
    }
    
    static void reQuickSort(vector<Type> & arr, int lhs, int rhs) {
        const int cutOff = 5;
        if (cutOff <= rhs - lhs) {
            // Partition
            int pivot = median3(arr, lhs, rhs);
            int i = lhs;
            int j = rhs - 1;
            while (1) {
                // When equal, stop
                while (arr[++i] < pivot) {}
                while (arr[--j] > pivot) {}
                if (i < j) {
                    swap(arr[i], arr[j]);
                }
                else {
                    break;
                }
            }
            swap(arr[i], arr[rhs - 1]);
            reQuickSort(arr, lhs, i - 1);
            reQuickSort(arr, i + 1, rhs);
        } else {
            _insertSort(arr, lhs, rhs);
        }
    }
    
    static void merge(vector<Type> & arr, vector<Type> & temp,
                      int left, int right, int rightEnd) {
        int leftEnd = right - 1;
        int tmpI = left;
        while (left <= leftEnd && right <= rightEnd) {
            if (arr[left] <= arr[right])
                temp[tmpI++] = arr[left++];
            else
                temp[tmpI++] = arr[right++];
        }
        while (left <= leftEnd) {
            temp[tmpI++] = arr[left++];
        }
        while (right <= rightEnd) {
            temp[tmpI++] = arr[right++];
        }
    }
    
    static void mergePass(vector<Type> & arr, vector<Type> & temp, int length) {
        int i = 0;
        for (i = 0; i + 2 * length <= arr.size(); i += 2 * length) {
            merge(arr, temp, i, i + length, i + 2 * length - 1);
        }
        // Solve the odd problem.
        if (i + length < arr.size()) {
            merge(arr, temp, i, i + length, arr.size() - 1);
        } else {
            for (int j = i; j < arr.size(); j++) {
                temp[j] = arr[j];
            }
        }
    }
    
    static void _insertSort(vector<Type> & arr, int lhs, int rhs) {
        for (int i = lhs; i <= rhs; i++) {
            for (int j = i; j > lhs && arr[j - 1] > arr[j]; j--) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
    
public:
    static void quickSort(vector<Type> & arr) {
        reQuickSort(arr, 0, arr.size() - 1);
        return;
    }
    
    static void quickSort2(vector<Type> & arr) {
        reQuickSort2(arr, 0, arr.size() - 1);
        return;
    }
    
    static void heapSort(vector<Type> & arr) {
        buildHeap(arr);
        for (int i = arr.size() - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    
    static void bubbleSort(vector<Type> & arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size() - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
    static void selectSort(vector<Type> & arr) {
        for (int i = 0; i < arr.size(); i++) {
            int min = i;
            for (int j = i + 1; j < arr.size(); j++) {
                min = arr[min] < arr[j] ? min : j;
            }
            swap(arr[i], arr[min]);
        }
    }
    
    static void insertSort(vector<Type> & arr) {
        _insertSort(arr, 0, arr.size() - 1);
    }
    
    static void shellSort(vector<Type> & arr) {
        for (int inc = arr.size() / 2; inc > 0; inc /= 2) {
            for (int i = 0; i < arr.size(); i += inc) {
                for (int j = i; j >= inc && arr[j - inc] > arr[j]; j -= inc) {
                    swap(arr[j - inc], arr[j]);
                }
            }
        }
    }
    
    static void mergeSort(vector<Type>& arr) {
        int length = 1;
        vector<Type> temp(arr);
        while (length < arr.size()) {
            mergePass(arr, temp, length);
            length *= 2;
            mergePass(temp, arr, length);
            length *= 2;
        }
    }
    
    static void bucketSort(vector<Type>& arr) {
        const int BUCKET_NUM = 10;
        vector<Type> buckets[BUCKET_NUM];
        Type min = arr[0];
        Type max = arr[0];
        // Find the range
        for (Type num : arr) {
            min = min < num ? min : num;
            max = max > num ? max : num;
        }
        int inc = floor((max - min) / BUCKET_NUM) + 1;
        for (Type num : arr) {
            buckets[int((num - min) / inc)].push_back(num);
        }
        arr = vector<Type>();
        for (int i = 0; i < BUCKET_NUM; i++) {
            sort(buckets[i].begin(), buckets[i].end());
            arr.insert(arr.end(), buckets[i].begin(), buckets[i].end());
        }
    }
    
    static void radixSort(vector<Type>& arr) {
        // Get the max digit
        int max = arr[0];
        for (Type num : arr) {
            max = max > num ? max : num;
        }
        int maxDigit = 0;
        while (max > 0) {
            maxDigit++;
            max /= 10;
        }
        // Sort
        vector<Type> tmp(arr.size(), 0);
        int radix = 1;
        for (int i = 0; i < maxDigit; i++) {
            vector<int> count(10, 0);
            for (Type num : arr) {
                count[(num / radix) % 10]++;
            }
            for (int j = 1; j < 10; j++) {
                count[j] += count[j - 1];
            }
            for (int j = arr.size() - 1; j >= 0; j--) {
                int k = (arr[j] / radix) % 10;
                tmp[--count[k]] = arr[j];
            }
            arr = tmp;
            radix *= 10;
        }
    }
};

template <typename Type>
void checkSort(void (*func)(vector<Type> &),
               const vector<Type> & ran_arr, const vector<Type> & std_arr) {
    vector<int> copy_arr(ran_arr);
    clock_t start, end;
    start = clock();
    func(copy_arr);
    end = clock();
    cout << '\t' << "Time cost:" << end - start << endl;
    if (std_arr == copy_arr) {
        cout << '\t' << "Correct" << endl;
    } else {
        cout << '\t' << "Fail: ";
        for (int num : copy_arr) {
            cout << num << ' ';
        }
        cout << endl;
    }
}



int main(int argc, const char * argv[]) {
    // Create test data
    const int MAX_TEXT_SIZE = 100000;
    vector<int> arr(MAX_TEXT_SIZE);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % MAX_TEXT_SIZE;
    }
    clock_t start, end;
    cout << "Standard sort:" << endl;
    vector<int> std_arr(arr);
    start = clock();
    sort(std_arr.begin(), std_arr.end());
    end = clock();
    cout << '\t' << "Time cost:" << end - start << endl;
    // My sort
    cout << "My quick sort:" << endl;
    checkSort(MySorts<int>::quickSort, arr, std_arr);
    
    cout << "My quick sort2:" << endl;
    checkSort(MySorts<int>::quickSort2, arr, std_arr);
    
    cout << "My bubble sort:" << endl;
    checkSort(MySorts<int>::bubbleSort, arr, std_arr);
    
    cout << "My heap sort:" << endl;
    checkSort(MySorts<int>::heapSort, arr, std_arr);
    
    cout << "My select sort:" << endl;
    checkSort(MySorts<int>::selectSort, arr, std_arr);
    
    cout << "My insertion sort:" << endl;
    checkSort(MySorts<int>::insertSort, arr, std_arr);
    
    cout << "My shell sort:" << endl;
    checkSort(MySorts<int>::shellSort, arr, std_arr);
    
    cout << "My merge sort:" << endl;
    checkSort(MySorts<int>::mergeSort, arr, std_arr);
    
    cout << "My radix sort:" << endl;
    checkSort(MySorts<int>::radixSort, arr, std_arr);
    
    cout << "My bucket sort:" << endl;
    checkSort(MySorts<int>::bucketSort, arr, std_arr);
    
    return 0;
}
