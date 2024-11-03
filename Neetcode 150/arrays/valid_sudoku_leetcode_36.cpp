#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/valid-sudoku/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(m*n)
// SC : O(m*n)
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int row_size = board.size();
        int col_size = board[0].size();

        map<int, vector<int>> rmap;
        map<int, vector<int>> cmap;

        for (int r = 0; r < row_size; r++) {
            for (int c = 0; c < col_size; c++) {
                if (board[r][c] != '.') {
                    rmap[r].push_back(board[r][c]);
                    cmap[c].push_back(board[r][c]);
                }
            }
        }

        bool rvalid = true;
        for (auto &x : rmap) {
            set<int> s(x.second.begin(), x.second.end());
            if (s.size() != x.second.size()) {
                rvalid = false;
                break;
            }
        }

        bool cvalid = true;
        for (auto &x : cmap) {
            set<int> s(x.second.begin(), x.second.end());
            if (s.size() != x.second.size()) {
                cvalid = false;
                break;
            }
        }

        bool isValid = true;
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<char> v(9, 0);
                for (int l = 0; l < 3; l++) {
                    for (int m = 0; m < 3; m++) {
                        if (board[i + l][j + m] != '.') {
                            int c = board[i + l][j + m] - '1';
                            if (v[c] == 0) {
                                v[c]++;
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return isValid && rvalid && cvalid;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '7'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    bool answer = sol.isValidSudoku(matrix);
    cout << boolalpha << answer << endl;
}
