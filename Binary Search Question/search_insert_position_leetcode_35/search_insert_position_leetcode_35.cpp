#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/search-insert-position/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (BruteForce)
// TC : O(n)
// SC : O(1)
class SolutionBruteForce {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return n;
    }
};

// Approach-2 (Binary Search)
// TC: O(logn)
// SC: O(1)
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;
        int ans = n;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    Solution sol;
    cout << "ans -->" << sol.searchInsert(nums, target) << endl;
}
