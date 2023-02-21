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

        // agar minIndex is not same as i index, then only sort
        // meaning if pointer is at i and minIndex is i we dont need to sort.
        // if condition is for optimization
        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main() {
    int arr[3] = {3, 2, 1};
    selection_sort(arr, 3);

    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
}