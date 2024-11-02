#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/contains-duplicate/
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
    bool isAnagram(string s, string t) {
        vector<int> smap(26, 0);
        vector<int> tmap(26, 0);

        for (auto &x : s) {
            smap[x - 'a']++;
        }

        for (auto &x : t) {
            tmap[x - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (smap[i] != tmap[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "nagaram";
    string t = "anagram";
    Solution sol;
    auto isValid = sol.isAnagram(s, t);
    cout << "is valid --> " << (isValid ? "true" : "false") << endl;
}