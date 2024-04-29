#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
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
    int minOperations(vector<int>& nums, int k) {
        int xorRes = nums[0];

        // Iterate and find xor result of all elements
        for (int i = 1; i < nums.size(); i++) {
            xorRes ^= nums[i];
        }

        // create 32 bit bitset to convert xorRes to bit representation for both xorRes & k
        bitset<20> xorBits(xorRes);
        bitset<20> xorK(k);
        int count = 0;

        // count total number of times where bit differs between xorRes & k
        for (int i = 0; i <= 20; i++) {
            if (xorBits[i] != xorK[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    vector<int> nums = {4, 40, 5, 41};
    Solution sol;
    int ans = sol.minOperations(nums, 40);
    cout << "ans --> " << ans << endl;
}

// My Intuition
// constrains were high so i thought it should be O(n) or O(logn) at minimum, that narrowed my mind to try O(n).
// So, lets take an example where we want to reach number 40, and forget number array for a minute

// Basics:
// lets apply XOR on any random number list:

// 00000000 00000000 00000000 00000100 -> 4
// 00000000 00000000 00000000 00101000 -> 40
// 00000000 00000000 00000000 00000101 -> 5
// 00000000 00000000 00000000 00101001 -> 41
// ------------------------------------------------
// 00000000 00000000 00000000 00000000 -> 0 (it has 0 active bits)
// ------------------------------------------------
// So, we have to go:
// from (xorFinal):
// 00000000 00000000 00000000 00000000
// active bits count: 0

// to (xorK):
// 00000000 00000000 00000000 00101000
// active bits count: 2

// Logically we can see we require 2 transformations at this point,
// to count them, we simply iterate over both bitsets and increment
// count by 1 where xorFinal[i] does not match xorK[i]