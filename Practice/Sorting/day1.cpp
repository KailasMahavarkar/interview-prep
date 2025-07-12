#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printArray(int arr[], int n)
{
    for (int x = 0; x < n; x++)
    {
        cout << arr[x] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            // if left side i is less than j swap
            if (arr[i] < arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    // loop through all the element 1 time.
    for (int i=1; i < n; i++){
        // copy the current value in temp
        int temp = arr[i];

        // backward loop from (i - 1) to 0
        int j=i-1;
        for (; j >= 0; j--){
            if (arr[j] > temp){
                // shift element to right
                arr[j + 1] = arr[j];
            }else{
                break;
            }
        }
        
        // since we executed for loop in backward
        // j-- is happening no matter what
        // thus we need correction on arr[j + 1]
        arr[j + 1] = temp;
    }

}


int partition(int arr[], int s, int e){
    // set inital pivot to arr[s]
    int pivot = arr[s];
    int counter = 0;

    // count elements less than pivot
    for (int i = s+1; i <= e; i++){
        if (arr[i] <= pivot){
            counter++;
        }
    }

    // swap counter with pivot
    int pIndex = s + counter;
    swap(arr[pIndex], arr[s]);


    int i=s;
    int j=e;

    while (i < pIndex && j > pIndex){

        while (arr[i] < pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }

        // cout << "swap" << arr[i] << arr[j] << endl;
        if (i < pIndex && j > pIndex){
            swap(arr[i++], arr[j--]);
        }


    }

    return pIndex;
}

void quick_sort(int arr[], int s, int e)
{
    if (s >= e){
        return;
    }

    int p = partition(arr, s, e);

    // sort left
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);

}

int main()
{

    int arr[7] = {3, 1, 4, 5, 2, 6};
    // int n = 7 - 1;

    
    // int p = partition(arr, 0, n);
    // quick_sort(arr, 0, n);
    insertion_sort(arr, 7);

    printArray(arr, 7);
    return 1;
}