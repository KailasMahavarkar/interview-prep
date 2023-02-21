#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i < n; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void bubbleSort(int arr[], int n){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            // cout << "i " << arr[i] << " j " << arr[j] << endl;;
            if (arr[j] > arr[i]){
                swap(arr[i], arr[j]);
                // cout << "swapping " << "arr[i]: " << arr[i] << " arr[j]" << arr[j] << endl;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    // loop through array once
    for (int i=1; i<n; i++){
        // save current element temp
        int temp = arr[i];

        // loop backwards starting from i-1 to 0
        int j=i-1;
        for (; j >= 0; j--){
            // compare j and temp
            if (arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i < n; i++){
        int minIndex = i;
        // get minimum 
        for (int j=i; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        // set minimum
        swap(arr[minIndex], arr[i]);
    }
}

void merge(int arr[], int s, int e){

    int mid = (s+e)/2;

    int len1 = (mid - s) + 1;
    int len2 = e - mid;

    // arr1 & arr2
    int *arr1 = new int(len1);
    int *arr2 = new int(len2);


    int mainIndex = s;
    for (int i = 0; i < len1; i++){
        arr1[i] = arr[mainIndex++];
    }

    // push elements to array2
    mainIndex = mid + 1;
    for (int i = 0; i< len2; i++){
        arr2[i] = arr[mainIndex++];
    }
    
    // merge two sorted arrays
    int i = 0;
    int j = 0;
    mainIndex = s;

    while (i < len1 && j < len2){
        if (arr1[i] < arr2[j]){
            arr[mainIndex] = arr1[i];
            i++;
            mainIndex++;
        }else{
            arr[mainIndex] = arr2[j];
            j++;
            mainIndex++;
        }
    }

    // copy all remaining elements from array1
    while(i < len1){
        arr[mainIndex] = arr1[i];
        mainIndex++;
        i++;
    }

    // copy all remaining elements from array1
    while(j < len2){
        arr[mainIndex] = arr2[j];
        mainIndex++;
        j++;
    }
    delete []arr1;
    delete []arr2;

}

void mergeSort(int arr[], int s, int e){

    // [5, 4, 3, 2, 1, 0]
    // [5, 4, 3]   | [2, 1, 0]
    // [5, 4] [3]  | [2, 1] [0]
    // [5] [4] [3] | [2] [1] [0]
    // [4, 5] [3]  | [1, 2] [0]
    // [3, 4, 5]   | [0, 1, 2]

    if (s >= e){
        return;
    }

    int mid =  (s+e) /2;
    // sort start to mid 
    mergeSort(arr, 0, mid);

    // sort mid to end
    mergeSort(arr, mid+1, e);

    // merge two sorted arrays
    merge(arr, s, e);
}

int partition(int arr[], int s, int e){
    // pass to place pivot at correct position
    // consider 1st element as pivot
    int pivotValue = arr[s];
    int count = 0;

    // count elements lower than pivot
    for (int i=s+1; i <= e; i++ ){
        if (arr[i] < pivotValue){
            count +=1;
        }
    }

    // calculate pivotIndex
    int pivotIndex = s + count;

    // swap current pivot with count index
    swap(arr[s], arr[pivotIndex]);

    int i=0;
    int j=e;
    while (i < pivotIndex && j > pivotIndex){
        while (arr[i] < pivotValue){
            i++;
        }
        while (arr[j] > pivotValue){
            j--;
        }
        // swap
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if (s >= e){
        return;
    }

    int pivotIndex = partition(arr, s, e);

    // 0 to pivotIndex
    quickSort(arr, s, pivotIndex - 1);

    // pivotIndex + 1 to end
    quickSort(arr, pivotIndex +1, e);

}

int main(){
    int arr[5] = {8, 4, 2, 5, 9};

    selectionSort(arr, 5);
    printArray(arr, 5);
}