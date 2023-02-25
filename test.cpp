#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int p = partition(arr, s, e);

    cout << p << endl;

    // sort left part
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int n = 5;
    int arr[n] = {3, 1, 4, 2, 6};
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
}