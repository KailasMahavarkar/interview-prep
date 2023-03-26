#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void segregateElements(int arr[], int n) {
        vector<int> positives;
        vector<int> negatives;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                negatives.push_back(arr[i]);
            else
                positives.push_back(arr[i]);
        }

        int counter = 0;
        for (int i = 0; i < positives.size(); i++) {
            arr[counter] = positives[i];
            counter++;
        }

        for (int j = 0; j < negatives.size(); j++) {
            arr[counter] = negatives[j];
            counter++;
        }
    }
};

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    obj.segregateElements(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}