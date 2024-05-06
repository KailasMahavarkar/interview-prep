#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        bitset<1001> seen;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int maxx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                seen[abs(nums[i])] = 1;
            } else {
                if (seen[nums[i]]) {
                    maxx = nums[i];
                }
            }
        }
        return maxx;
    }
};

int main() {
    vector<int> nums = {-1, 2, -3, 3};
    Solution sol;
    int ans = sol.findMaxK(nums);
    cout << "ans --> " << ans << endl;
}
