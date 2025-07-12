#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 9 steps...
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void bubbleSortOptimized(int a[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int temp = arr[i];

        int j = i - 1;
        while (j >= 0) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            }
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minimum = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minimum]) {
                minimum = j;
            }
        }
        swap(arr[minimum], arr[i]);
    }
}

void merge(int arr[], int s, int e) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create two arrays
    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;

    // copy content of arr to arr1
    for (int i = 0; i < len1; i++) {
        arr1[i] = arr[mainIndex++];
    }

    // copy content of arr to arr2
    mainIndex = mid + 1;
    for (int j = 0; j < len2; j++) {
        arr2[j] = arr[mainIndex++];
    }

    // merge two sorted arrays
    int i = 0;
    int j = 0;
    mainIndex = s;

    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            arr[mainIndex++] = arr1[i++];
        } else {
            arr[mainIndex++] = arr2[j++];
        }
    }

    // copy remaining elements to arr1
    while (i < len1) {
        arr[mainIndex++] = arr1[i++];
    }

    // copy remaining elements to arr2
    while (j < len2) {
        arr[mainIndex++] = arr2[j++];
    }
    delete[] arr1;
    delete[] arr2;
}

// its a recusive function
void mergeSort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);      // mid - s + 1
    mergeSort(arr, mid + 1, e);  // e - mid
    merge(arr, s, e);
}

int partititon(int arr[], int s, int e) {
    // set mid
    int mid = (s + e) / 2;

    int pivotValue = arr[s];
    int count = 0;

    // count elements less than pivotIndex(initally arr[s])
    for (int i = 1; i <= e; i++) {
        if (arr[i] < pivotValue) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < arr[pivotIndex]) {
            i++;
        }

        while (arr[j] > arr[pivotIndex]) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {
    // base case
    if (s >= e) {
        return;
    }

    int p = partititon(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[3] = {3, 2, 1};

    bubbleSort(arr, 3);

    // bubble(arr, 3);

    // insertionSort(arr, 5);

    // selectionSort(arr, 5);

    // mergeSort(arr, 0, 4);

    // quickSort(arr, 0, 4);
    printArray(arr, 3);
}