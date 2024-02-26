#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    int n;
    int dp[100001];
    bool solve(vector<int>& nums, int idx) {
        if (idx >= n) {
            return true;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        bool result = false;

        if (idx + 1 < n && nums[idx] == nums[idx + 1]) {
            result = result || solve(nums, idx + 2);
        }

        if (idx + 2 < n && nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
            result = result || solve(nums, idx + 3);
        }

        if (idx + 2 < n && nums[idx + 1] - nums[idx] == 1 && nums[idx + 2] - nums[idx + 1] == 1) {
            result = result || solve(nums, idx + 3);
        }

        return dp[idx] = result;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};

int main() {
    vector<int> nums = {2, 2, 2, 3, 4, 5, 5, 5};
    Solution sol;
    bool answer = sol.validPartition(nums);
    cout << boolalpha << "answer --> " << answer << endl;
}