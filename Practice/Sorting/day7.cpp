#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

void bubbleSort(int arr[], int n){
    for (int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if (arr[j] > arr[i]){
                swap(arr[j], arr[i]);
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for (int i=0; i < n; i++){
        int temp = arr[i];

        int j = i-1;
        while(j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
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
        swap(arr[minIndex], arr[i]);
    }
}


void merge(int arr[], int s, int e){
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create two arrays
    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;

    // copy content from mainArray to new arrays one by one
    for (int i=0; i < len1; i++){
        arr1[i] = arr[mainIndex++];
    } 

    mainIndex = mid + 1;
    for (int j=0; j < len2; j++){
        arr2[j] = arr[mainIndex++];
    }


    // merge two sorted arrays
    int i=0;
    int j=0;
    mainIndex = s;

    while (i < len1 && j < len2){
        // whichever is smaller select that
        if(arr1[i] < arr2[j]){
            arr[mainIndex++] = arr1[i++];
        }else{
            arr[mainIndex++] = arr2[j++];
        }
    }
    // copy elements from array 1;
    while(i < len1){
        arr[mainIndex++] = arr1[i++];
    }
    while(j < len2){
        arr[mainIndex++] = arr2[j++];
    }
    delete []arr1;
    delete []arr2;
}

// its a recursive algorithm
void mergeSort(int arr[], int s, int e){
    
    if (s >= e){
        return;
    }
    
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);  // -> mid - s + 1
    mergeSort(arr, mid+1, e); // -> e - m
    merge(arr, s, e);

}


int partition(int arr[], int s, int e){
    int mid = (s+e)/2;
    int count = 0;
    int pivotValue = arr[s]; // 3

    for (int i=1; i <= e; i++){
        if (arr[i] < pivotValue){
            count++;
        }
    }

    // count -> 2
    // pivotValue -> 3

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i=s;
    int j=e;
    
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < arr[pivotIndex]){
            i++;
        }

        while(arr[j] > arr[pivotIndex]){
            j--;
        }

        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if (s >= e){
        return;
    }

    int p = partition(arr, s, e);
    cout << p << endl;
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){

    int arr[5] = {3, 1, 4, 2, 6};
    // bubbleSort(arr, 5);
    // selectionSort(arr, 5);
    // mergeSort(arr, 0, 4);
    quickSort(arr, 0, 4);
    printArray(arr, 5);
    
}