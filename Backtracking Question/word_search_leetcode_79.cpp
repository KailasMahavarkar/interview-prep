#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/word-search/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(4^n)
class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int m, n;
    bool find(vector<vector<char>> &board, string &word, int i, int j, int idx) {
        // base case for success
        if (idx >= word.length()) {
            return true;
        }

        // base case for failure
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) {
            return false;
        }

        // backtracking begins
        char temp = board[i][j];
        board[i][j] = '#';
        for (auto &dir : directions) {
            if (find(board, word, i + dir[0], j + dir[1], idx + 1)) {
                return true;
            }
        }
        board[i][j] = temp;
        // backtracking ends

        return false;
    }
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (find(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> arr = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution sol;
    bool result = sol.exist(arr, "ABCCED");
    cout << "ans --> " << boolalpha << result << endl;
}
