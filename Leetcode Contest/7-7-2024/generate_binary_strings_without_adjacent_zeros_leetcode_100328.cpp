#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/contest/weekly-contest-405/problems/generate-binary-strings-without-adjacent-zeros/description/
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
    int N;
    void solve(vector<string> &res, string temp, int idx) {
        if (idx == N) {
            res.push_back(temp);
            return;
        }

        if (idx == 0 || temp[idx - 1] == '1') {
            temp[idx] = '0';
            solve(res, temp, idx + 1);
        }

        temp[idx] = '1';
        solve(res, temp, idx + 1);
    }
    vector<string> validStrings(int n) {
        N = n;
        vector<string> res;
        string temp(n, '0');

        solve(res, temp, 0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> ans = sol.validStrings(4);

    for (auto &x : ans) {
        cout << "x --> " << x << endl;
    }
}
