#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr1 = {2, 3, 4, 4, 7};
    vector<int> arr2 = {0, 4, 4, 5};

    int n1 = arr1.size();
    int n2 = arr2.size();

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr2[j] << " ";
                arr2[j] = -1;
            }
        }
    }
}