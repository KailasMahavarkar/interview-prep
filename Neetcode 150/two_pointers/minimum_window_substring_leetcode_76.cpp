#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/minimum-window-substring/description/
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
    bool isValid(vector<int> fullMap, vector<int> halfMap) {
        int n = fullMap.size();
        for (int i = 0; i < n; i++) {
            if (halfMap[i] < fullMap[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> windowMap(26, 0);
        vector<int> stringMap(26, 0);

        for (auto &x : t) stringMap[x - 'A']++;

        int requiredSize = t.size();
        int currentSize = 0;
        int l = 0;

        int minLen = INT_MAX;
        int minLeft = 0;

        for (int r = 0; r < s.size(); r++) {
            int c = s[r] - 'A';
            windowMap[c]++;  // a new char came which is within window

            while (isValid(stringMap, windowMap)) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minLeft = l;
                }

                windowMap[s[l] - 'A']--;
                l++;  // decrease window by incrementing left
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    string s, t;
    s = "ADOBECODEBANC", t = "ABC";
    Solution sol;
    auto ans = sol.minWindow(s, t);
    cout << "ans -->" << ans;
}