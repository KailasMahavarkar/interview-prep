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
// TC : O(N!)
// SC : O(N ^ 2)
class Solution {
   public:
    int N;
    vector<vector<string>> result;

    bool isSafe(vector<string> &board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        int i, j;

        i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = row, j = col;
        while (i >= 0 && j < N) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, vector<string> &board) {
        if (row == N) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; ++col) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                solve(row + 1, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        result.clear();
        vector<string> board(N, string(N, '.'));
        solve(0, board);
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
