#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
    Company Tags   : None
    Youtube Link   : https://www.youtube.com/watch?v=RoEzdG1bB9s
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Backtracking)
// TC : O(2^n)
// SC : O(n)
class Solution {
   public:
    int n;
    int result = 0;
    void solve(vector<int> &nums, unordered_map<int, int> &hmap, int idx, int k) {
        if (idx >= n) {
            result++;
            return;
        }

        // dont pick
        solve(nums, hmap, idx + 1, k);

        // take
        if (!hmap[nums[idx] - k] && !hmap[nums[idx] + k]) {
            hmap[nums[idx]]++;
            solve(nums, hmap, idx + 1, k);
            hmap[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int> &nums, int k) {
        n = nums.size();
        unordered_map<int, int> hmap;
        solve(nums, hmap, 0, k);
        return result - 1;  // excluding empty subset
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 4, 6};
    int ans = sol.beautifulSubsets(nums, 2);
    cout << "ans --> " << ans << endl;
}