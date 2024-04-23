#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
    Company Tags   : Microsoft
    Youtube Link   : https://www.youtube.com/watch?v=MqMvkrkerIY
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n*L) -> without memo its O(n*2^n)
// SC : O(n)   -> without memi its O(1)
class Solution {
   public:
    int n;
    unordered_map<string, int> hmap;
    bool hasCommon(string &s1, string &s2) {
        bitset<26> bs;

        for (auto &x : s1) {
            if (bs[x - 'a'] > 0) {
                return true;
            }
            bs[x - 'a'] = 1;
        }

        for (auto &x : s2) {
            if (bs[x - 'a'] > 0) {
                return true;
            }
        }

        return false;
    }

    int solve(vector<string> &arr, int idx, string temp) {
        if (idx >= n) {
            return temp.length();
        }

        if (hmap.find(temp) != hmap.end()) {
            return hmap[temp];
        }

        int include = 0;
        int exclude = 0;

        if (hasCommon(arr[idx], temp)) {
            exclude = solve(arr, idx + 1, temp);
        } else {
            exclude = solve(arr, idx + 1, temp);
            include = solve(arr, idx + 1, temp + arr[idx]);
        }

        return hmap[temp] = max(include, exclude);
    }

    int maxLength(vector<string> &arr) {
        string temp = "";
        hmap.clear();
        n = arr.size();
        return solve(arr, 0, temp);
    }
};

int main() {
    vector<string> arr = {"un", "iq", "ue"};
    Solution sol;
    int ans = sol.maxLength(arr);
    cout << "ans --> " << ans << endl;
}