#include <algorithm>
#include <climits>
#include <cmath>
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
    vector<vector<int>> dp;
    int MOD = (int)(1e9 + 7);
    int subsetSumCount(vector<int>& nums, int sum) {
        int n = nums.size();
        // ------------ TOP DOWN -----------------
        // when no other elements are present
        // if (n == 0){
        //     return false;
        // }
        // // when element is found
        // if (sum == 0){
        //     return true;
        // }

        // if (nums[n - 1] > target){
        //     // we cannot find any subset if nums[n-1] is more than target
        //     return subsetSum(nums, sum, n - 1);
        // }else{
        //     // choices -> pick or dont pick last element from array
        //     int pick = subsetSum(nums, sum - nums[n - 1], n - 1);
        //     int unpick = subsetSum(nums, sum - nums[n - 1], n -1);
        //     return pick || unpick;
        // }
        // ----------- END TOP DOWN ---------------

        dp.resize(n + 1, vector<int>(sum + 1, -1));

        // initalize dp
        int k = 1;
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0 && j > 0) {
                    dp[i][j] = 0;
                }
                if (j == 0 && i > 0) {
                    if (nums[i - 1] == 0) {
                        dp[i][j] = pow(2, k);
                        k++;
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        int count = 0;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (nums[i - 1] > j) {
                    // we cannot find any subset if nums[n-1] is more than target
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // choices -> pick or dont pick last element from array
                    int pick = dp[i - 1][j - nums[i - 1]];
                    int unpick = dp[i - 1][j];
                    dp[i][j] = (pick + unpick) % MOD;
                }
            }
        }

        return dp[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // Let's find the total sum of the array elements.
        int totalSum = 0;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // s1 + s2 = totalsum
        // s1 - s2 = diff
        // -------------------
        // 2s1 = totalsum + diff
        // s1 = (totalsum + diff) / 2

        // agar s1 - s2 correct h then vo gurantee dega if we found s1 with value 'x' tabhi
        // difference d aya hoga
        // thus instead of finding difference direcltly between subsets
        // we find how many times s1 has occured
        // jitne baar bhi s1 aya hoga utne baar difference 'd' hoga
        if ((totalSum + target) % 2 != 0) {
            return 0;
        } else {
            int ans = subsetSumCount(nums, (totalSum + target) / 2);
            return ans;
        }
    };
};

int main() {
    int d = 3;
    vector<int> arr = {1, 1, 1, 1, 1};

    Solution sol;
    int ans = sol.findTargetSumWays(arr, d);
    cout << "ans: " << ans << endl;
    return 0;
}