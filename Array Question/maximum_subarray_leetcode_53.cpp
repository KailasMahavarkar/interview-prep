#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/maximum-subarray/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)

class Solution {
   public:
    // Kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int lmax = 0;        // Local maximum
        int gmax = INT_MIN;  // Global maximum

        for (int x = 0; x < nums.size(); x++) {
            lmax = lmax + nums[x];
            // gmax = max(lmax, gmax)
            if (lmax > gmax) {
                gmax = lmax;
            }

            // Reset local maximum to 0 if it becomes negative
            if (lmax < 0) {
                lmax = 0;
            }
        }
        return gmax;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
    return 0;
}