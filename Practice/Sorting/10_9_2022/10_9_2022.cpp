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

int partititon(int *arr, int s, int e){

    int mid = s + (e - s) / 2;
    int pivot = arr[s];
    int count = 0;

    // count element less than pivot
    for (int i=s; i <= e; i++){
        if (arr[i] < pivot){
            count++;
        }
    }


    int pivotIndex = count + s;
    swap(arr[pivotIndex], arr[s]);


    int i = 0;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot){
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

    int p = partititon(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e); 
}

int main(){
    int arr[5] = {5, 4, 3, -2, 1};
    quickSort(arr, 0, 4);
    printArray(arr, 5);
}