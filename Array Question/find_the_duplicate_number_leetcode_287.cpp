#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/find-the-duplicate-number/
    Company Tags   : FAANG
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        // detect cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // After detecting the cycle
        // the slow pointer is reset to the beginning of the array
        // and both pointers move at the same pace(one step at a time) until they meet
        // The meeting point is the duplicate element
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution sol;
    cout << sol.findDuplicate(nums) << endl;
}