#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (arr[minIndex] != arr[i]) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main() {
    int arr[3] = {2, 1, 4, 0, 5};
    selection_sort(arr, 3);

    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
}