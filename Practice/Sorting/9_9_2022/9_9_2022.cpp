#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printArray(int *arr, int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void bubbleSort(int *arr, int size){
    for (int i=0; i<size;i++){
        for (int j=0; j<size; j++){
            if (arr[j] > arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(int *arr, int size){
    for (int i=0; i<size;i++){
        int temp = arr[i];

        int j = i - 1;
        while(j >= 0 && temp < arr[j]){
            arr[j+1] = arr[j]; 
            j--;
        }
        arr[j+1] = temp;
    }
}


void selectionSort(int *arr, int size){
    for (int i=0; i < size - 1; i++){
        int minIndex = i;
        for (int j=i+1; j < size; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void merge(int *arr, int s, int e){
    int mid = s + ((e-s) /2);

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;

    // fill content from mainIndex to array 1
    for (int i=0; i < len1; i++){
        arr1[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;

    // fill content from mainIndex to array 1
    for (int i=0; i < len1; i++){
        arr2[i] = arr[mainIndex++];
    }

    // merge two sorted arrays
    int i = 0;
    int j = 0;
    mainIndex = s;

    while(i < len1 && j < len2){
        if (arr1[i] < arr2[j]){
            arr[mainIndex++] = arr1[i++];
        }else{
            arr[mainIndex++] = arr2[j++];
        }
    }

    while(i < len1){
        arr[mainIndex++] = arr1[i++];
    }

    while(j < len2){
        arr[mainIndex++] = arr2[j++];
    }

    delete []arr1;
    delete []arr2;

}

void mergeSort(int *arr, int s, int e){
    if (s >= e){
        return;
    }

    int mid = s + ((e-s) /2); 
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}


int partition(int *arr, int s, int e){
    int mid = s + (e - s) / 2;
    int counter = 0;
    int pivot = arr[s];

    // count element less than pivot
    for (int i=s; i <= e; i++){
        if (arr[i] < pivot){
            counter++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + counter;
    swap(arr[pivotIndex], arr[s]);

    int i = 0;
    int j = e;

    while (i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int *arr, int s, int e){
    if (s >= e){
        return;
    }

    int mid = s + (e - s) / 2;
    int pivot = partition(arr, s, e);

    // sort left side of pivot
    quickSort(arr, s, pivot-1);

    // sort right side of pivot
    quickSort(arr, pivot+1, e);
    
}

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, 4);
    printArray(arr, 5);
}