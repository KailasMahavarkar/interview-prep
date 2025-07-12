#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/burst-balloons/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O(n^2)
// SC : O(n^2)

class Solution {
   public:
    int dp[305][305];
    vector<int> nums;

    int solve(int i, int j) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int result = 0;

        for (int m = i + 1; m < j; m++) {
            result = max(
                result,
                (nums[m] * nums[i] * nums[j]) + solve(i, m) + solve(m, j));
        }

        return dp[i][j] = result;
    }
    int maxCoins(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();

        this->nums.insert(this->nums.begin(), 1);
        this->nums.push_back(1);
        memset(dp, -1, sizeof(dp));

        return solve(0, n + 1);
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.maxCoins(nums) << endl;
}
