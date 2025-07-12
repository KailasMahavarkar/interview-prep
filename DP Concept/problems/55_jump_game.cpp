#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool solve(vector<int> &nums, vector<int> &dp, int i) {
        // if person has reached to end
        // this can only be true if previous people said he can jump
        if (dp[nums.size() - 1]) {
            return true;
        }

        // person with 0 points cannot jump further
        if (nums[i] == 0) {
            dp[i] == false;
        }

        for (int j = 0; j < nums[i + 1]; j++) {
            solve(nums, dp, j);
        }

        return false;
    }

    bool canJump(vector<int> &nums) {
        vector<int> dp(nums.size() + 1);
        return solve(nums, dp, 0);
    }
};

int main() {
    vector<int> nums = {1, 1, 1};
    Solution sol;
    int result = sol.canJump(nums);
    cout << "can jump " << boolalpha << (!!result) << endl;
}