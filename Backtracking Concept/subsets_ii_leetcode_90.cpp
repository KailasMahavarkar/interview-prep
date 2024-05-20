#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/subsets-ii/
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
    vector<vector<int>> answer;
    void solve(vector<int>& nums, vector<int>& temp, int idx) {
        answer.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            if (i == idx || nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
                solve(nums, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, temp, 0);
        return answer;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};

    Solution sol;
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    for (auto& arr : ans) {
        for (auto& x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
}
