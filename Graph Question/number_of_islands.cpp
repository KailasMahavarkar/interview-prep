#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    // void dfs(grid, visited, i, j);
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();

        if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || grid[i][j] == '0') {
            return;
        }
        visited[i][j] = true;

        // all 8 directions
        for (int p = -1; p <= 1; p++) {
            for (int q = -1; q <= 1; q++) {
                dfs(grid, visited, i + p, j + q);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution sol;
    cout << sol.numIslands(grid) << endl;

    return 0;
}