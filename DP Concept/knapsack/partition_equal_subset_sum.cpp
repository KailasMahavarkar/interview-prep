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

// Recursion + Memo
class SolutionMemo {
public:
    int target;
    vector<vector<bool>> dp;
    bool isSubsetSumHelper(vector<int> arr, int sum, int n) {
        // base case for success
        // we found collection of elements that sum up to 0
        if (sum == 0) {
            return true;
        }

        // base case for success
        // when n reached 0 it means we have exhausted all elements
        if (n == 0) {
            return false;
        }

        if (dp[n][sum]) {
            return true;
        }

        // if last element is more than target ignore it and move to next
        if (arr[n - 1] > sum) {
            dp[n][sum] = isSubsetSumHelper(arr, sum, n - 1);
        } else {
            bool pickCase = isSubsetSumHelper(arr, sum - arr[n - 1], n - 1);
            bool unpickCase = isSubsetSumHelper(arr, sum, n - 1);
            dp[n][sum] = pickCase || unpickCase;
        }

        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i=0; i<nums.size(); i++){
            total += nums[i];
        }

        if (total % 2 == 1){
            return false;
        }

        dp.resize(nums.size() + 1, vector<bool>(total + 1, false));
        bool ans = isSubsetSumHelper(nums, total / 2, nums.size());
        return ans;
    }
};

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