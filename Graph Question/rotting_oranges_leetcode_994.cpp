#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isSafe(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<pair<int, int>> que;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
            }
        }

        int tm = 0;
        while (!que.empty()) {
            int levelSize = que.size();

            for (int k = 0; k < levelSize; k++) {
                int r = que.front().first;
                int c = que.front().second;
                que.pop();

                // Visit neighbors
                for (auto& dir : directions) {
                    int _r = dir[0] + r;
                    int _c = dir[1] + c;

                    if (isSafe(_r, _c) && grid[_r][_c] == 1) {
                        que.push({_r, _c});
                        grid[_r][_c] = 2;  // Mark the orange as rotten
                    }
                }
            }

            if (!que.empty()) {
                tm++;  // Increment time only if there are more levels to process
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;  // There are fresh oranges left
                }
            }
        }

        return tm;
    }
};

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution sol;
    int ans = sol.orangesRotting(grid);
    cout << "ans --> " << ans << endl;
}
