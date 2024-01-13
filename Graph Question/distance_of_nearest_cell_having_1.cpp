#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> que;

        // fill all nodes having 1 into its answer
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    que.push({{i, j}, 0});
                    visited[i][j] = 1;
                } else {
                    visited[i][j] = 0;
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while (!que.empty()) {
            int row = que.front().first.first;
            int col = que.front().first.second;
            int steps = que.front().second;
            que.pop();
            distance[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    que.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return distance;
    }
};
