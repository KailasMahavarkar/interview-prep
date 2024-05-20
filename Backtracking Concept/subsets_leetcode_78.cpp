#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/subsets/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    vector<vector<int>> ans;

    void solve(vector<int> nums, vector<int> temp, int idx) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // exclude wala call
        solve(nums, temp, idx + 1);

        // include wala call
        temp.push_back(nums[idx]);
        solve(nums, temp, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp, 0);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};

    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);
    for (auto& arr : ans) {
        for (auto& x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
}
