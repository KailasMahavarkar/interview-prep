#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    cout << "n is " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[5];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printArray(arr, n);
}