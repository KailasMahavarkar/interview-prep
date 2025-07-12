#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printDP(vector<vector<int>> dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

// Method 1: recursion + memoization
class SolutionMemo {
   public:
    vector<vector<int>> dp;
    int m, n;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        // when either of length of array goes out of bound are return 0
        if (i >= m || j >= n) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (nums1[i] == nums2[j]) {
            // we draw line and move on
            dp[i][j] = 1 + solve(i + 1, j + 1, nums1, nums2);
        } else {
            // we have two options
            // we can fix i or we can fix j at each position of i and j

            int fix_i = solve(i, j + 1, nums1, nums2);
            int fix_j = solve(i + 1, j, nums1, nums2);

            dp[i][j] = max(fix_i, fix_j);
        }

        return dp[i][j];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        dp.resize(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, nums1, nums2);
    }
};

// Method 2: tabulation
class Solution {
   public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                // 1. base case
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }

                // 2. choice diagram
                else if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    vector<int> nums1 = {1, 4, 2};
    vector<int> nums2 = {1, 2, 4};

    Solution s;
    cout << s.maxUncrossedLines(nums1, nums2) << endl;
    return 0;
}