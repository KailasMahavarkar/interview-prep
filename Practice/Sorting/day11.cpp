#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

void insertionSort(int arr[], int n){
    for (int i=0; i<n;i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selectionSort(int arr[], int n){
    for (int i =0; i<n; i++){
        int minimum = i;
        for (int j=i+1; j<n;j++){
            if (arr[j] < arr[minimum]){
                minimum = j;
            }
        }
        if (minimum != i){
            swap(arr[i], arr[minimum]);
        }
    }
}

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;

    int len1 = mid - s + 1; // 3
    int len2 = e - mid; // 2

    // create two arrays
    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;
    for (int i=0; i<len1; i++){
        arr1[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for (int j=0; j<len2; j++){
        arr2[j] = arr[mainIndex++];
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

    // cleanup
    delete []arr1;
    delete []arr2;
}

void mergeSort(int arr[], int s, int e){
    if (s >= e){
        return;
    }
    int mid = (s+e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e); 
    merge(arr, s, e);
}

int main(){
    int n = 5;
    int arr[n] = {3, 1, 4, 7, 0};
    mergeSort(arr, 0, 4);
    printArray(arr, n);
}