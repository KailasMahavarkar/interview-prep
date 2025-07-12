#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Problem is exactly same as longest common substring
// syntax is just better

class Solution {
   public:
    int result = 0;
    vector<vector<int>> dp;
    int LCS(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        // when either string1 or string2 is empty
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        LCS(nums1, nums2, n - 1, m);
        LCS(nums1, nums2, n, m - 1);

        // our answer can only exists within this range
        // why? since we have made all possible recursive calls where for where 1st char of both string does not match
        // now if it matches... we can say 1 + solve(..)
        // since this was done after previous recursive calls... it guranteed to have valid answer as long as we
        // keep track of current maximum... which when recursion rolls back its global maximum
        if (nums1[n - 1] == nums2[m - 1]) {
            int take = 1 + LCS(nums1, nums2, n - 1, m - 1);
            result = max(result, take);
            return dp[m][n] = take;
        } else {
            return dp[m][n] = 0;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        dp.resize(m + 1, vector<int>(n + 1, -1));
        LCS(nums1, nums2, m, n);
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    Solution sol;
    int ans = sol.findLength(nums1, nums2);
    cout << "ans --> " << ans << endl;
}