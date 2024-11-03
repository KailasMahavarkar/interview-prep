#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int sum = nums[s] + nums[e];
            if (sum == target) {
                return {s + 1, e + 1};
            } else if (sum < target) {
                s++;
            } else if (sum > target) {
                e--;
            }
        }

        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution sol;
    vector<int> answer = sol.twoSum(nums, 9);

    for (auto x : answer) {
        cout << x << " ";
    }
    cout << endl;
}
