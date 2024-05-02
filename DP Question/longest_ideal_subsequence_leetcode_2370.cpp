#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/longest-ideal-subsequence/description/
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
    int solve(string s, int idx, int prevIndex, int k) {
        if (idx >= n) {
            return 0;
        }

        int pick = 0;
        int dontPick = 0;

        if (s[prevIndex] > s[idx]) {
            pick = solve(s, idx + 1, idx, k);
        }
    }
    int longestIdealString(string s, int k) {
        n = s.length();
        return solve(s, 0, -1, k);
    }
};

int main() {
    string s = "acfgbd";
    int k = 2;
    Solution sol;
    int ans = sol.longestIdealString(s, k);
    cout << "ans --> " << ans << endl;
}