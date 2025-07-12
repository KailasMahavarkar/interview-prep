#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[j] > arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for (int i=0; i<n;i++){
        int temp = arr[i];

        // loop backwards 
        int j=i-1;
        while(j >= 0){
            if (arr[j] > temp){
                arr[j+1] = arr[j];
            }
            j--;
        }
        // filling the gap
        arr[j+1] = temp;
    }
}

void selectionSort(int arr[], int n){
    for (int i=0; i < n; i++){
        int minIndex = i;

        for (int j=i+1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
        
    }
}

void merge(int arr[], int s, int e){
    int mid = (s+e) / 2;

    // calculate length of array 1
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create 2 new arrays of same lengths
    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;
    // copy content from mainArray to arr1 & arr2
    for (int i=0; i < len1; i++){
        arr1[i] = arr[mainIndex++];
    }

    // set mainIndex
    mainIndex = mid + 1;
    // copy content from mainArray to arr1 & arr2
    for (int j=0; j < len2; j++){
        arr2[j] = arr[mainIndex++];
    }

    // merge two sorted arrays
    int i=0;
    int j=0;
    mainIndex = s;

    while (i < len1 && j < len2){
        if (arr1[i] < arr2[j]){
            arr[mainIndex++] = arr1[i++];
        }else{
            arr[mainIndex++] = arr2[j++];
        }
    }

    // copy all elements from array1 
    while (i < len1){
        arr[mainIndex++] = arr1[i++];
    }

    while (j < len2){
        arr[mainIndex++] = arr2[j++];
    }

    delete []arr1;
    delete []arr2;
}

void mergeSort(int arr[], int s, int e){
    if (s >= e){
        return;
    }

    int mid = (s+e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int partition(int arr[], int s, int e){
    int mid = (s+e) /2;
    int pivotValue = arr[s];
    int count = 0;
    // count element
    for (int i=1; i <= e; i++){
        if (arr[i] < pivotValue){
            count++;
        }
    }

    // swap arr[s] with count
    // place element in correct position
    // s -> pivotIndex corrected for 'n' partitions
    int pivotIndex = count + s;
    swap(arr[s], arr[pivotIndex]);

    
    // create two pointers
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex){

        while (arr[i] < arr[pivotIndex]){
            i++;
        }

        while (arr[j] > arr[pivotIndex]){
            j--;
        }

        // reason why this check if performed is because of while loop
        // position of (i, j) may get change
        // thus swap only if necessary
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
        
    }
    return pivotIndex;
}

// quick sort -> recursive
void quickSort(int arr[], int s, int e){

    if (s >= e){
        return;
    }

    // int mid = (s+e) /2;
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, 4);
    
    printArray(arr, 5);
}