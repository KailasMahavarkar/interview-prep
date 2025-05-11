#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : None
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    void solve(int n, vector<int> &arr) {
        sort(arr.begin(), arr.end());

        vector<int> ans(arr.size());

        int j = n - 1;
        for (int i = 0; i < n; i += 2) {
            ans[i] = arr[j];
            j--;
        }

        j = 0;
        for (int i = 1; i < n; i += 2) {
            ans[i] = arr[j];
            j++;
        }

        int cheapCount = 0;
        for (int i = 1; i + 1 < ans.size(); i++) {
            if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
                cheapCount++;
            }
        }

        cout << cheapCount << endl;

        for (auto &x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sol.solve(n, arr);

    // Solution sol;
    // vector<int> arr = {1, 2, 3, 4, 5};
    // sol.solve(5, arr);
}
