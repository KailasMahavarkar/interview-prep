#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : average case O(logn) | worst case O(n)
// SC : O(1)
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else if (nums[mid] < nums[e]) {
                e = mid;
            } else {
                e--;
            }
        }

        return nums[s];
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 1, 2, 3};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}