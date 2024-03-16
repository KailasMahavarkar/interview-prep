#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/longest-string-chain/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Recursion + Memo)
// TC : O(n*n)
// SC : O(n*2)
class Solution {
    vector<vector<int>> dp;

   public:
    int maxTurbulenceSize(vector<int>& arr) {
        dp = vector<vector<int>>(arr.size(), vector<int>(2, 0));
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            res = max(res, max(1 + algo(arr, i + 1, 1), 1 + algo(arr, i + 1, 0)));
        }
        return res;
    }

    int algo(vector<int>& arr, int idx, int flag) {
        if (idx >= arr.size()) return 0;
        if (dp[idx][flag] != 0) return dp[idx][flag];

        int res = 0;

        if (flag == 0) {
            // if flag is 0 (meaning decreasing)
            // WE ARE CURRENLTY LOOKING AT DECREASING SEQUENCE
            // if arr[idx] >= arr[idx - 1] meaning... if current value is more than previous it is increasing sequence
            // which is incorrect -> so we return 0
            // now remember, our current length is valid so we increment answer, but since previous was decreasing
            // we have to look for increasing

            // gist(repeat words)
            // inside the flag 0... we are talking about current
            // it means, current has to be decreasing sequence then next will be increasing
            if (arr[idx] >= arr[idx - 1]) return 0;
            res = 1 + algo(arr, idx + 1, 1);
        } else {
            if (arr[idx] <= arr[idx - 1]) return 0;
            res = 1 + algo(arr, idx + 1, 0);
        }

        dp[idx][flag] = res;
        return res;
    }
};

int main() {
    vector<int> arr = {1, 3, 2};
    Solution sol;
    int ans = sol.maxTurbulenceSize(arr);
    cout << "ans --> " << ans << endl;
}