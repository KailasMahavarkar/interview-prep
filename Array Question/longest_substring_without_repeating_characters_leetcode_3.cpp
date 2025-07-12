#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (two pointer)
// TC : O(n)
// SC : O(1)

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;  // stable pointer
        int r = 0;  // changing pointer
        unordered_map<char, int> mapp;
        int ans = 0;

        while (r < s.length()) {
            // teleport [l] to value from map
            if (mapp.find(s[r]) != mapp.end()) {
                l = max(mapp[s[r]] + 1, l);
            }

            // update mapp to current right
            mapp[s[r]] = r;

            // compute answer and maximum
            ans = max(ans, r - l + 1);
            r++;
        }

        cout << ans << endl;
        return ans;
    }
};

int main() {
    Solution solution;
    solution.lengthOfLongestSubstring("abba");
    return 0;
}
