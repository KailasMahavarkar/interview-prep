#include <bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>> dp) {
    for (auto x : dp) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Solution 1: recursion
// TC = O(2^n)
// SC = O(n^2)
class SolutionRecursive {
   public:
    int LIS(vector<int>& arr, int index, int prevIndex) {
        // 1. base case
        if (index == arr.size()) {
            return 0;
        }

        // 2. code flow
        int pick = 0;
        int unpick = 0;

        // if we dont pick it then we should keep prevIndex as same
        unpick = LIS(arr, index + 1, prevIndex);

        // we are doing comparision since we want longest increasing
        if (arr[index] > arr[prevIndex]) {
            // if we do pick it then we should update prevIndex
            pick = 1 + LIS(arr, index + 1, arr[index]);
        }
        return max(pick, unpick);
    }
    int longestIncreasingSubsequence(vector<int> arr) {
        return LIS(arr, 0, -1);
    }
};

// Solution 2: recursion + memoization
// TC = O(n^2)
// SC = O(n^2)
class SolutionMemo {
   public:
    vector<vector<int>> dp;
    int LIS(vector<int>& nums, int index, int prevIndex) {
        // 1. base case
        if (index == nums.size()) {
            return 0;
        }

        // check in memo
        if (dp[index][prevIndex + 1] != -1) {
            return dp[index][prevIndex + 1];
        }

        // 2. choice diagram
        int pick = 0;
        int unpick = 0;

        unpick = 0 + LIS(nums, index + 1, prevIndex);

        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            pick = 1 + LIS(nums, index + 1, index);
        }

        return dp[index][prevIndex + 1] = max(pick, unpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n + 1, -1));
        return LIS(nums, 0, -1);
    }
};

// Solution 2: tabulation
// TC = O(n^2)
// SC = O(n)
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n, 1);

        // recursive relation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<int> sample = {5, 4, 11, 1, 16, 8};
    Solution sol;
    int ans = sol.lengthOfLIS(sample);

    cout << "ans --> " << ans << endl;
}