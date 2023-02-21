#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

void bubbleSort(int *arr, int n){
    // for (int i=0; i<n;i++){
    //     for (int j=0; j<n;j++){
    //         cout << boolalpha << "arr[i] " << arr[i] << " arr[j] " << arr[j]  << " i>j " << (arr[i] > arr[j])  << endl;
    //         if (arr[j] > arr[i]){
    //             swap(arr[i], arr[j]);
    //         }
    //     }
    // }
    // cout << i << " " << j << " " << arr[i] << " " << arr[j]<< " " << endl;
    // break;
}

int main(){
    int arr[3] = {3, 2, 1};
    bubbleSort(arr, 3);
    printArray(arr, 3);
}