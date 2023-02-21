#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void bubbleSort(int arr[], int n){
    for (int i=0; i < n; i++){
        for (int j=0; j<n;j++){
            if (arr[j] > arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n){
    // loop through array once
    for (int i=0; i < n; i++){
        // store arr[i] into temp
        int temp = arr[i];

        // loop backwards from i-1 to 0
        int j=i-1; 
        while(j >= 0){
            if (arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }
}

// pointer based sorting
// swapping is needed once per round
void selectionSort(int arr[], int n){
    for (int i=0; i<n; i++){
        int minIndex = i;

        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;

    // calc length of 1st half
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // make new array of same lengths
    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    // copy elements to array1
    int mainIndex = s;
    for (int i=0; i<len1;i++){
        arr1[i] = arr[mainIndex++];
    }

    // set main index to mid+1;
    mainIndex = mid+1;
    for (int j=0; j<len2; j++){
        arr2[j] = arr[mainIndex++];
    }

    // merge two sorted arrays
    int i=0;
    int j=0;
    mainIndex = s;

    while(i < len1 && j < len2){
        if (arr1[i] < arr2[j]){
            arr[mainIndex++] = arr1[i++];
        }else{
            arr[mainIndex++] = arr2[j++];
        }
    }

    // copy all remaining elements from array1
    while(i < len1){
        arr[mainIndex++] = arr1[i++];
    }

    // copy all remaining elements from array2
    while(j < len2){
        arr[mainIndex++] = arr2[j++];
    }

    delete []arr1;
    delete []arr2;
}

void mergeSort(int arr[], int s, int e){

    // base case
    if (s >= e){
        return;
    }

    int mid = (s + e) /2;

    // sort start to (mid - 1)
    mergeSort(arr, s, mid);

    // sort mid to right
    mergeSort(arr, mid+1, e);

    // merge sorted arrays
    merge(arr, s, e);
}

int partition(int arr[], int s, int e){
    int mid = (s+e)/2;
    int pivotValue = arr[s];
    // loop through all elements and count elements less than pivot
    int count = 0;
    for (int i=1; i <= e; i++){
        if (arr[i] < pivotValue){
            count++;
        }
    }

    int pivotIndex = count + s;
    swap(arr[pivotIndex], arr[s]);

    // sort all elements such that 
    // elements less than pivot are on left
    // elements more than pivot are on right

    // two pointer approach
    int i=0;
    int j=e;

    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] < pivotIndex){
            i++;
        }
        while(arr[j] > pivotIndex){
            j--;
        }

        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }

    }
    
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    // base case 
    if (s >= e){
        return;
    }

    int pivotIndex = partition(arr, s, e);
    quickSort(arr, s, pivotIndex - 1);
    quickSort(arr, pivotIndex+1, e);
}

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, 4);
    printArray(arr, 5);
}