#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/jump-game/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class SolutionMemo {
   public:
    int dp[10001];
    int n;
    bool solve(vector<int>& nums, int idx) {
        if (idx == n - 1)
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (int i = 1; i <= nums[idx]; i++) {
            if (solve(nums, idx + i)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};

class Solution {
   public:
    int n;
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int> t(n, false);
        t[0] = true;

        // see the code you will get the logic
        // basically if j which is always in past can jump to 'i' then i is reachable
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j + nums[j] >= i && t[j]) {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n - 1];
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    bool ans = sol.canJump(nums);
    cout << "ans --> " << boolalpha << ans << endl;
}