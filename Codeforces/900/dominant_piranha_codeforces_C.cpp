#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(vector<int> &arr) {
        int n = arr.size();

        int maxVal = *max_element(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (arr[i] == maxVal) {
                // check left only if valid
                // check right only if valid
                if (
                    (i > 0 && (arr[i] > arr[i - 1])) ||
                    (i < n - 1 && (arr[i] > arr[i + 1]))) {
                    cout << i + 1 << endl;
                    return;
                }
            }
        }

        cout << "-1" << endl;
    }
};

int main() {
    int t;
    cin >> t;

    Solution sol;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sol.solve(a);
    }

    // vector<int> arr = {5, 3, 4, 6, 2, 0};
    // Solution sol;
    // sol.solve(arr);
    return 0;
}