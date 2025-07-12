#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Optimal -> binary search)
// TC : O(logn)
// SC : O(1)
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            if (nums[s] <= nums[e]) {
                return nums[s];
            }

            int mid = s + (e - s) / 2;

            if (nums[s] > nums[mid]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> arr = {4, 5, 6, 1, 2, 3};
    Solution sol;
    cout << sol.findMin(arr) << endl;
    return 0;
}