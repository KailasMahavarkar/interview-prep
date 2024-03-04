#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/jump-game-ii/description/
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
    int solve(vector<int> &nums, int idx) {
        // person has reached end of journey
        if (idx >= nums.size() - 1) {
            return 0;
        }

        if (dp[idx]) {
            return dp[idx];
        }

        int minJumps = INT_MAX - 1;

        // i = idx + 1     -> starting window is idx+1 ... anywhere in array
        // nums[idx] + idx -> ending window has be nums[idx] + idx
        // since starting window was +idx .. thus ending window is also +idx (think carefully and you will know why)
        // its like you are sliding a box over array.. the box is variable length but has minimum window length of idx

        for (int i = idx + 1; i <= nums[idx] + idx; i++) {
            minJumps = min(minJumps, 1 + solve(nums, i));
        }

        return dp[idx] = minJumps;
    }

    int jump(vector<int> &nums) {
        memset(dp, 0, sizeof(dp));
        return solve(nums, 0);
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    int ans = sol.jump(nums);
    cout << "ans --> " << ans << endl;
}