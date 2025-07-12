#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Problem is also called: lastStoneWeightII (leetcode)
// Video explaination: https://www.youtube.com/watch?v=FB0KUhsxXGY

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

class SolutionMemo {
   public:
    int t[31][5051];
    int minDiffSubset(vector<int>& stones, int n, int s1, int sum) {
        if (n == 0)
            return abs(sum - 2 * s1);

        if (t[n][s1] != -1)
            return t[n][s1];

        int take = minDiffSubset(stones, n - 1, s1 + stones[n - 1], sum);
        int dont_take = minDiffSubset(stones, n - 1, s1, sum);

        return t[n][s1] = min(take, dont_take);
    }
    int minimumDifference(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int sum = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();
        return minDiffSubset(nums, n, 0, sum);
    }
};
class Solution {
   public:
    vector<vector<bool>> dp;
    vector<int> isSubsetSum(vector<int>& nums, int n, int sum) {
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