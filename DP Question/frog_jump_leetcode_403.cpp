#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/frog-jump/description/
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
    int n;
    unordered_map<int, int> mp;
    int dp[2002][2002];
    bool solve(vector<int>& stones, int currStoneIndex, int prevJump) {
        // base case for success
        if (currStoneIndex == n - 1) {
            return true;
        }

        if (dp[currStoneIndex][prevJump] != -1) {
            return dp[currStoneIndex][prevJump];
        }

        bool result = false;

        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            // since we cant jump backwards and we have stones index starting from 0th index itself
            if (nextJump > 0) {
                int nextStone = stones[currStoneIndex] + nextJump;  // <-- this line is game
                // check if nextJump stone is valid
                if (mp.find(nextStone) != mp.end()) {
                    result = result || solve(stones, mp[nextStone], nextJump);
                }
            }
        }
        return dp[currStoneIndex][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;

        n = stones.size();
        memset(dp, -1, sizeof(dp));
        // map [stone -> index] -> we need to know at every momemt in time during recursion if stone exists before jumping
        // either we can do this or do binary search O(nlogn) vs O(1) | although space is traded
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        return solve(stones, 0, 0);
    }
};

int main() {
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    Solution sol;
    bool result = sol.canCross(stones);
    cout << boolalpha << "can cross --> " << result << endl;
}
