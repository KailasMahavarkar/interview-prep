#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
    Company Tags   : Microsoft
    Youtube Link   : https://youtu.be/Nk0qHfNqM18
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(logn)
// SC : O(1)
class Solution {
   public:
    int findIndex(vector<int>& nums, int target, int s, int e, bool isLeft) {
        int idx = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                idx = mid;

                if (isLeft) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        // left most index
        int left = findIndex(nums, target, s, e, true);

        // right most index
        int right = findIndex(nums, target, s, e, false);

        return {left, right};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution sol;
    vector<int> indexes = sol.searchRange(nums, target);
    cout << "left: " << indexes[0] << " right: " << indexes[1] << endl;
}