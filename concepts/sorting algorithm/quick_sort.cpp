#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i< n; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

int partition(int *arr, int s, int e){
    int pivot = arr[s];

    int counter = 0;
    // count all elements less than pivot
    for (int i=s+1; i <= e; i++){
        if (arr[i] <= pivot){
            counter++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + counter;
    swap(arr[pivotIndex], arr[s]);

    int i =0;
    int j =e;

    while (i < pivotIndex && j > pivotIndex){
        while (arr[i] < pivot){
            i++;
        }
        while(arr[j] < pivot){
            j--;
        }
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s ,int e)
{
    if (s >= e){
        return;
    }

    int p = partition(arr, s, e);

    // sort left part
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main()
{

    int n = 5;
    int arr[n] = {5, 4, 3, 2, 1};
    quickSort(arr, 0 , n - 1);
    printArray(arr, n);

    return 0;
}
