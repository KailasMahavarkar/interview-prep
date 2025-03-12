#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(int n, vector<int>& arr) {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        for (int i = 0; i < n; i++) {
            minElement = min(minElement, arr[i]);
            maxElement = max(maxElement, arr[i]);
        }

        cout << (maxElement - minElement) << endl;
    }
};

int main() {
    int T;
    cin >> T;

    Solution sol;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sol.solve(n, arr);
    }

    // vector<int> arr = {61, 61, 61};
    // sol.solve(3, arr);

    return 0;
}
