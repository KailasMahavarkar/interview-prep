#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/path-with-maximum-gold/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/


// Approach-1 (Normal)
// TC : O(m*n * 4^(m*n))
// SC : O(m*n) <- stack space
class Solution {
   public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int x, int y) {
        return x < m && x >= 0 && y < n && y >= 0;
    }
    int DFS(vector<vector<int>>& grid, int i, int j) {
        if (!isSafe(i, j) || grid[i][j] == 0) {
            return 0;
        }

        int originalGoldValue = grid[i][j];
        grid[i][j] = 0;

        int localMax = 0;
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            localMax = max(localMax, DFS(grid, new_i, new_j));
        }

        grid[i][j] = originalGoldValue;

        return originalGoldValue + localMax;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxx = max(maxx, DFS(grid, i, j));
                }
            }
        }
        return maxx;
    }
};


int main() {
    vector<vector<int>> grid = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
    Solution sol;
    int ans = sol.getMaximumGold(grid);
    cout << "ans -->" << ans << endl;
}
