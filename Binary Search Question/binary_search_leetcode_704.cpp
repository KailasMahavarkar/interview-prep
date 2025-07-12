#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/binary-search/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(1)
// SC : O(nlogn)
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution sol;
    cout << "ans -->" << sol.search(nums, target) << endl;
}
