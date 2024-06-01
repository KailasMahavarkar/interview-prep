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
    int N;
    vector<vector<string>> result;
    vector<pair<int, int>> directions = {
        {-1, 2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {1, 2},
        {1, -2},
        {2, -1},
        {2, 1}};

    set<int> occupied_row;
    set<int> occupied_col;

    bool isSafe(int x, int y, int row, int col) {
        bool isBoundaryValid = x >= 0 && x < N && y >= 0 && y < N;
        if (!isBoundaryValid) {
            return false;
        }

        // left diagonal
        for (int i = 0; i < N; i++) {
            
        }

        // right diagonal

        // rows

        // cols
    }

    void solve(int n, int x, int y, vector<string> &temp) {
        if (n == 0) {
            result.push_back(temp);
        }

        temp[x][y] = 'Q';

        for (auto &dir : directions) {
            int _x = x + dir.first;
            int _y = y + dir.second;

            if (isSafe(_x, _y) && temp[_x][_y] == '.') {
                solve(n - 1, _x, _y, temp);
            }
        }

        temp[x][y] = '.';
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;

        // create a nxn grid
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                s += '.';
            }
            temp.push_back(s);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                solve(n, i, j, temp);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(4);

    for (auto combinationVec : ans) {
        for (auto combination : combinationVec) {
            for (auto &line : combination) {
                cout << line << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // for (auto x : ans) {
    //     for (auto ch : x) {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }
}
