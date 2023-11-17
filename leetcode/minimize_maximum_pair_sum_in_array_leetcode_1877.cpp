#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link  : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array
    Company Tags  : amazon
*/

// Approach-1 (greedy -> sort + twopointer)
// TC : O(nlogn)
// SC : O(1)

class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;

        int maxPairSum = INT_MIN;
        while (i < j) {
            int currPairSum = nums[i] + nums[j];
            maxPairSum = max(currPairSum, maxPairSum);
            i++;
            j--;
        }

        return maxPairSum;
    }
};

int main() {
    vector<int> nums = {3, 5, 4, 2, 4, 6};
    Solution sol;
    int ans = sol.minPairSum(nums);
    cout << "maxPairSum --> " << ans << endl;
}