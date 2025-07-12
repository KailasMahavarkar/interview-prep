#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(m*n*k(depth of recursion stack))
// SC : O(m*n)
class Solution {
   public:
    int m, n;
    vector<vector<int>> dp;
    int NEG_INFINITY = INT_MIN / 2;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == m || j == n) {
            return NEG_INFINITY;
        }

        if (dp[i][j] != NEG_INFINITY) {
            return dp[i][j];
        }

        // case 1 -> we simply multiple nums1[i] * nums2[j]
        int val = nums1[i] * nums2[j];

        // case 2 ->  we simply multiple nums1[i] * nums2[j] + call recursion function()
        int take_i_j = val + solve(nums1, nums2, i + 1, j + 1);

        // case 3 -> we pick from nums1 only
        int take_i = solve(nums1, nums2, i, j + 1);

        // case 4 -> we pick from nums2 only
        int take_j = solve(nums1, nums2, i + 1, j);

        return dp[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        dp.resize(m + 1, vector<int>(n + 1, NEG_INFINITY));

        int answer = solve(nums1, nums2, 0, 0);
        return answer;
    }
};
int main() {
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    Solution sol;
    int answer = sol.maxDotProduct(nums1, nums2);
    cout << "answer --> " << answer << endl;
}
