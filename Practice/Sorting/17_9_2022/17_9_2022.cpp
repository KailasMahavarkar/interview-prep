#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
// sorting and searching
// merge sort, quick sort, binary search

using namespace std;

void printArray(int *arr, int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

void merge(int arr[], int s, int e){
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create two arrays
    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;

    // add content to newly created arrays
    for (int i=0; i < len1; i++){
        arr1[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for (int j=0; j < len2; j++){
        arr2[j] = arr[mainIndex++];
    }

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

    delete []arr1;
    delete []arr2;

}

void mergeSort(int arr[], int s, int e){
    if (s >= e){
        return;
    }

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);

}

int partition(int arr[], int s, int e){

    int pivot = arr[s];
    int count = 0;

    // count elements less than pivot
    for (int i=s; i <= e; i++){
        if (arr[i] < pivot){
            count++;
        }
    }

    // add 1st element to its correct position
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i=0;
    int j=e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

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

    int mid = s + (e - s) / 2;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

// iterative way
int binarySearch(int arr[], int s, int e, int target){
    while (s <= e){
        int mid = s + (e - s) / 2;

        // check if mid is target
        if (arr[mid] == target){
            return mid;
        }

        if (arr[mid] > target){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return -1;
}

// recursive way
int binarySearchRecursive(int arr[], int s, int e, int target){
    if (s >= e){
        return -1;
    }

    int mid = s + (e-s)/2;

    if (arr[mid] == target){
        return mid;
    }

    if (arr[mid] > target){
        // abandon right [....|xxxxx] and search left
        return binarySearchRecursive(arr, s, mid - 1, target);
    }else{
        // abandon left [xxxxx|....] and search right
        return binarySearchRecursive(arr, mid + 1, e, target);
    }

}




int kadansAlgo(int *arr, int n){

    int lmax =  0;
    int gmax = INT_MIN;
    int currSum = 0;

    for (int i=0; i < n; i++){
        currSum = arr[i] + currSum;

        // reset curr sum
        if (currSum < 0){
            currSum = 0;
        }
        lmax = max(currSum, lmax);
        gmax = max(lmax, gmax);
    }

    return gmax;
}


int main(){
    // int arr[6] = {};
    // mergeSort(arr, 0, 5);
    // quickSort(arr, 0, 5);

    // int res = binarySearch(arr, 0, 5, 3);
    // int res = binarySearchRecursive(arr, 0, 5, 3);

    int arr[5] = {3, -3, 1, 2, 4};
    int res = kadansAlgo(arr, 5);

    cout << res << endl;
    // printArray(arr, 6);
}
