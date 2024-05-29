#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/n-queens/
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;

        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(10);

    for (auto x : ans) {
        for (auto ch : x) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
