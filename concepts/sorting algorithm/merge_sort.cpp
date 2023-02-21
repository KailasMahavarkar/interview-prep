#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int x=0; x < n; x++){
        cout << arr[x] << " ";
    } cout << endl;
}


void merge(int *arr, int s, int e){
    int mid = (s + e) / 2;

    int len1 = (mid - s) + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];


    int mainIndex = s;
    for(int i=0; i<len1; i++) {
        arr1[i] = arr[mainIndex++];
    }

    mainIndex = mid+1;
    for(int i=0; i<len2; i++) {
        arr2[i] = arr[mainIndex++];
    }


    int i = 0;
    int j = 0;
    mainIndex = s;

    while (i < len1 && j < len2){
        if (arr1[i] < arr2[j]){
            arr[mainIndex] = arr1[i];
            mainIndex++;
            i++;
        }else{
            arr[mainIndex] = arr2[j];
            mainIndex++;
            j++;
        }
    }

    // copy remaining from arr1
    while (i < len1){
        arr[mainIndex] = arr1[i];
        i++;
        mainIndex++;
    }
    
    // copy remaining from arr1y
    while (j < len2){
        arr[mainIndex] = arr2[j];
        j++;
        mainIndex++;
    }
    delete []arr1;
    delete []arr2;
}


void mergeSort(int *arr, int s, int e){
    printArray(arr, e - s + 1);
    // base case
    if (s >= e){
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}


int main(){
    int arr[7] = {6, 5, 4, 3, 2, 1, 0};

    mergeSort(arr, 0, 6);

    cout << "final -->";
    printArray(arr, 7);
    return 0;
}