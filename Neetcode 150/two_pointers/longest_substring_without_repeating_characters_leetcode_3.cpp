#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lmap;
        int n = s.size();

        int l = 0;
        int r = 0;
        int maxLen = 0;

        while (r < n) {
            if (lmap.find(s[r]) != lmap.end()) {  // if we already have value -> we saw that char somewhere
                l = max(lmap[s[r]] + 1, l);       // teleport to loc + 1 to continue next best search
            }

            lmap[s[r]] = r;  // we have to update current character location
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

int main() {
    string s = "abcabcbb";
    Solution sol;
    int ans = sol.lengthOfLongestSubstring(s);
    cout << "ans --> " << ans << endl;
}
