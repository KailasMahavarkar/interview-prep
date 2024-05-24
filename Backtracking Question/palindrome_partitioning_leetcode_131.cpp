#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/palindrome-partitioning/description
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
    vector<vector<string>> result;
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string &s, int idx, vector<string> curr) {
        if (idx == n) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < n; i++) {
            // if (isPalindrome(s, idx, i)) {
            curr.push_back(s.substr(idx, i - idx + 1));
            backtrack(s, i + 1, curr);
            curr.pop_back();
            // }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> curr;
        backtrack(s, 0, curr);
        return result;
    }
};

int main() {
    string s = "aab";
    Solution sol;
    vector<vector<string>> ans = sol.partition(s);
    for (auto &arr : ans) {
        for (auto &x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
}
