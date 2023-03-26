#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> commonElements(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3) {
        int i = 0, j = 0, k = 0;
        set<int> s;

        while (i < n1 && j < n2 && k < n3) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                s.insert(arr1[i]);
                i++;
                j++;
                k++;
            } else if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr2[j] < arr3[k]) {
                j++;
            } else {
                k++;
            }
        }

        vector<int> result(s.begin(), s.end());

        return result;
    }
};

int main() {
    int arr1[6] = {1, 5, 10, 20, 40, 80};
    int arr2[5] = {6, 7, 20, 80, 100};
    int arr3[8] = {3, 4, 15, 20, 30, 70, 80, 120};

    Solution sol;
    vector<int> result = sol.commonElements(
        arr1, arr2, arr3,
        sizeof(arr1) / sizeof(arr1[0]),
        sizeof(arr2) / sizeof(arr2[0]),
        sizeof(arr3) / sizeof(arr3[0])
    );
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}