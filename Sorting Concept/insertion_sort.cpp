#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *arr, int n) {
    // right wale ko increment karo
    for (int i = 1; i < n; i++) {
        // temp ke ander 1st index pe jo bhi hoga usko put karo
        // i -> 1st se hi start hoga so vo valid h
        int temp = arr[i];

        // iterate backwards starting from i - 1 to 0
        int j = i - 1;
        while (j >= 0) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                // break karna h
                break;
            }
            j--;
        }

        // since j-- is happening first
        // thus we need to correct out code to j+1 index
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
        swap(arr[i], arr[minimum]);
    }
}

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    selectionSort(arr, 5);
    printArray(arr, 5);
}