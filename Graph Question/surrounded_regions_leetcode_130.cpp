#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<vector<bool>> visited;
    int m, n;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    bool isBoundary(int i, int j) {
        return i == 0 || i == m - 1 || j == 0 || j == n - 1;
    }

    void DFS(vector<vector<char>>& board, int i, int j) {
        if (visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        for (auto& dir : directions) {
            int _i = i + dir[0];
            int _j = j + dir[1];

            if (isSafe(_i, _j) && !visited[_i][_j] && board[_i][_j] == 'O') {
                DFS(board, _i, _j);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        visited.resize(m, vector<bool>(n, false));

        // this will give all 'O' which are connected to boundary as marked true
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isBoundary(i, j) && !visited[i][j] && board[i][j] == 'O') {
                    DFS(board, i, j);
                }
            }
        }

        // we then iterate 2nd time
        // if item is 'O' and its not been marked as visited... its safe to turn to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if (!visited[i][j]) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'X'}};

    Solution sol;
    sol.solve(board);

    cout << "visited" << endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << sol.visited[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "board" << endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}