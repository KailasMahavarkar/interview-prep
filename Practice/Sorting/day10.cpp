#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void insertionSort(int arr[], int n){
    
    for (int i=0; i<n; i++){
        int temp = arr[i];

        // loop backwards
        int j = i - 1;
        while (j >= 0) {
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

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
        {
            swap(arr[minIndex], arr[i]);
        }
    }
}


int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    insertionSort(arr, 5);
    printArray(arr, 5);
}