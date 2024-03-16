#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/longest-string-chain/description/
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
    bool predecessor(const string& prev, const string& curr) {
        int m = prev.length();
        int n = curr.length();

        if (n - m != 1 || m >= n)
            return false;

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (prev[i] == curr[j])
                i++;
            j++;
        }
        return i == m;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string x, string y) {
            return x.length() < y.length();
        });

        int n = words.size();
        vector<int> t(n, 1);
        int result = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (predecessor(words[j], words[i])) {
                    t[i] = max(t[i], 1 + t[j]);
                    result = max(result, t[i]);
                }
            }
        }

        return result;
    }
};

int main() {
    vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    Solution sol;
    cout << "ans --> " << sol.longestStrChain(words) << endl;
}