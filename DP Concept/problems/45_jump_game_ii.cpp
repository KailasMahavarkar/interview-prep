#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int solve(vector<int> &nums, vector<int> &dp, int start) {
        // person has reached end of journey
        if (start >= nums.size() - 1) {
            return 0;
        }

        if (dp[start]){
            return dp[start];
        }


        int min_jump = INT_MAX;
        for (int i = start + 1; i <= nums[start] + start; i++) {
            min_jump = min(min_jump, 1 + solve(nums, dp, i));
        }
        dp[start] = min_jump;

        return dp[start];
    }

    void jump(vector<int> &nums) {
        vector<int> dp(nums.size() + 1);
        int min_ans = solve(nums, dp, 0);

        // print dp
        for (int i = 0; i < dp.size(); i++) {
            cout << dp[i] << " ";
        } cout << endl;

        cout << "answer --> " << min_ans << endl;
    }
};

int main() {
    vector<int> nums = {2, 1, 3, 1, 1, 2, 1, 1, 2, 1, 1, 1};
    Solution sol;
    sol.jump(nums);
    // cout << "can jump " << result << endl;
}