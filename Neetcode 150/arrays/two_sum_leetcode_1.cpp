#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/two-sum/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
        }

        for (int i = 0; i < nums.size(); i++) {
            int remainder = target - nums[i];

            if (hmap.find(remainder) != hmap.end() && i != hmap[remainder]) {
                return {hmap[remainder], i};
            } else {
                hmap[nums[i]] = i;
            }
        }

        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
