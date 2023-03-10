#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    cout << "n is " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool canParition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    return total % 2 == 0;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool ans = canParition(arr, n);
    cout << "ans: " << boolalpha << ans << endl;

    printArray(arr, n);
}