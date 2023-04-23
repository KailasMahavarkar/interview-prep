#include <bits/stdc++.h>
using namespace std;

void printDP(string msg, vector<vector<bool>>& dp) {
    cout << msg << " " << endl;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
class Solution {
   public:
    bool subsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // when sum is 0 answer is always true
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    bool pickCase = dp[i - 1][j - nums[i - 1]];
                    bool unpickCase = dp[i - 1][j];
                    dp[i][j] = pickCase || unpickCase;
                }
            }
        }

        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        if (total % 2 == 1) {
            return false;
        }
        return subsetSum(nums, total / 2);
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 1};
    bool ans = Solution().canPartition(nums);
    cout << boolalpha << ans << endl;
}