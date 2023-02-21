#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    for (int i=0; i<size;i++){
        cout << arr[i] << " ";
    } cout << endl;
}

int part(int arr[], int s, int e){
    int mid = (s+e)/2;
    int pivotValue = arr[s];
    int cnt = 0;
    for (int i=1; i <= e; i++){
        if (arr[i] < pivotValue){
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    // two pointer approach to fix elements on left and right
    int i=0;
    int j=e;
    while (i < pivotIndex && j > pivotIndex){

        while(arr[i] < arr[pivotIndex]){
            i++;
        }

        while (arr[j] > arr[pivotIndex]){
            j--;
        }

        // swap
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;


}

void selectionSort(int arr[], int s, int e){

    // base case
    if (s >= e){
        return;
    }

    int mid = (s+e) / 2;
    int p = part(arr, s, e);
    selectionSort(arr, s, p-1);
    selectionSort(arr, p+1, e);
}

int main(){

    int arr[5] = {5, 4, 3, 2, 1};
    selectionSort(arr, 0, 4);

    printArray(arr, 5);


}