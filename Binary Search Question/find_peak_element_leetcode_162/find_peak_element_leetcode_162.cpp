#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/find-peak-element/description/
    Company Tags   : None
    Youtube Link   : https://youtu.be/m4QAns43QSg
    Custom  Link   : None
    Similarities   : LC 852. Peak Index in a Mountain Array
*/

// Approach-1 (Normal)
// TC : O(logn)
// SC : O(1)
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        if (n == 1) return 0;
        if (n == 2) return nums[0] > nums[1] ? 0 : 1;

        // -INF [1, 2, 3, 1] -INF
        //            n-2 n-1 n

        // is 0th element my peak?
        if (-INT_MAX < nums[0] && nums[0] > nums[1]) {
            return 0;
        }

        // is last element my peak?
        if (nums[n - 2] < nums[n - 1] && nums[n - 1] > -INT_MAX) {
            return n - 1;
        }

        while (s < e) {
            int mid = s + (e - s) / 2;

            // take a guess -> mid is not at left
            if (nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return s;
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 4, 1};
    Solution sol;
    int peak = sol.findPeakElement(arr);
    cout << "peak: " << peak << endl;
}
