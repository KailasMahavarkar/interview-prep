#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Two Pointers)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        return t.length() - j;
    }
};

int main() {
    Solution sol;
    string s = "coaching";
    string t = "coding";
    int ans = sol.appendCharacters(s, t);
    cout << "ans -->" << ans << endl;
}