#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/contains-duplicate/description/
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
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, bool> hmap;

        for (auto &x : nums) {
            if (hmap[x]) {
                return true;
            }
            hmap[x] = true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    sol.containsDuplicate(nums);
}