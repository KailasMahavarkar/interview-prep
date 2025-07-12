#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printDP(string msg, vector<vector<bool>>& dp) {
    cout << msg << " " << endl;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
   public:
    vector<vector<bool>> dp;
    vector<int> isSubsetSum(vector<int>& nums, int n, int sum) {
        // if (n == 0) {
        //     return false;
        // }

        // // target is found
        // if (sum == 0) {
        //     return true;
        // }

        // // when prev value is more than sum available
        // if (nums[n - 1] > sum) {
        //     return isSubsetSum(nums, n - 1, sum);
        // } else {
        //     int pick = isSubsetSum(nums, n - 1, sum - nums[n - 1]);
        //     int unpick = isSubsetSum(nums, n - 1, sums);
        //     return pick || unpick;
        // }

        // initalize dp
        dp.resize(n + 1, vector<bool>(sum + 1, false));

        // init table
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (j == 0) {
                    dp[i][j] = true;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    int pick = dp[i - 1][j - nums[i - 1]];
                    int unpick = dp[i - 1][j];
                    dp[i][j] = pick || unpick;
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < sum / 2 + 1; i++) {
            if (dp[n][i] == true) {
                ans.push_back(i);
            }
        }

        printDP("after dp:", dp);

        return ans;
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        vector<int> ans = isSubsetSum(nums, n, sum);

        int minn = INT_MAX;
        for (int i = 0; i < ans.size(); i++) {
            minn = min(minn, sum - (2 * ans[i]));
        }

        return minn;
    }
};

int main() {
    vector<int> nums = {1, 6, 11, 5};
    Solution sol;
    int ans = sol.minimumDifference(nums);
    cout << "ans: " << ans << endl;
}