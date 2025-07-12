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
    int visitedCount = 0;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    bool isBoundary(int i, int j) {
        return i == 0 || i == m - 1 || j == 0 || j == n - 1;
    }

    void DFS(vector<vector<int>>& board, int i, int j) {
        if (visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        visitedCount++;

        for (auto& dir : directions) {
            int _i = i + dir[0];
            int _j = j + dir[1];

            if (isSafe(_i, _j) && !visited[_i][_j] && board[_i][_j] == 1) {
                DFS(board, _i, _j);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.resize(m, vector<bool>(n, false));

        // this will give all 'O' which are connected to boundary as marked true
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isBoundary(i, j) && !visited[i][j] && grid[i][j] == 1) {
                    DFS(grid, i, j);
                }
            }
        }

        int totalLandCell = 0;
        // we then iterate 2nd time
        // if item is 'O' and its not been marked as visited... its safe to turn to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    totalLandCell++;
                }
            }
        }

        return totalLandCell - visitedCount;
    }
};

int main() {
    vector<vector<int>> board = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution sol;
    sol.numEnclaves(board);

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