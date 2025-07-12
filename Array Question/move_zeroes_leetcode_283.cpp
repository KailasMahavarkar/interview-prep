#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/move-zeroes/description/
    Company Tags   : FAANG
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)

class Solution {
   public:
    void moveZeroes(std::vector<int>& nums) {
        int slow = 0;

        // slow -> will store index for non-zero element
        // fast -> will look for non-zero
        // when fast finds non-zero, and slow finds zero, swap them
        // if slow finds non-zero, increment slow

        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[slow] == 0 && nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
            }

            if (nums[slow] != 0) {
                slow++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}