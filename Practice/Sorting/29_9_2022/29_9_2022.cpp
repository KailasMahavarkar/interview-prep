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
    for (int i=0; i<n; i++){
        for (int j=0; j<n;j++){
            if (arr[i] < arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n){

    for (int i = 0; i < n; i++){
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
    for (int i=0; i< n; i++){
        int minIndex = i;
        for (int j=i+1; j < n; j++){
            if (arr[j] < arr[i]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){
    int arr[6] = {5, 4, 3, 2, 1, 0};
    selectionSort(arr, 6);
    printArray(arr, 6);
}