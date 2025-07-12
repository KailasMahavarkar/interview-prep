#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef pair<int, pair<int, int>> ppi;

// Note: since all weight are 1 ... queue can be used instead of min-heap

class Solution {
   public:
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));  // result is also M x N matrix

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            int total_weight = pq.top().first;
            pair<int, int> coordinates = pq.top().second;

            int x = coordinates.first;
            int y = coordinates.second;
            pq.pop();

            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int curr_weight = 1;

                if (isSafe(x_, y_) && grid[x_][y_] == 0) {
                    if (total_weight + curr_weight < result[x_][y_]) {
                        pq.push({total_weight + curr_weight, {x_, y_}});
                        grid[x_][y_] = 1;
                        result[x_][y_] = total_weight + curr_weight;
                    }
                }
            }
        }

        if (result[m - 1][n - 1] == INT_MAX) {
            return -1;
        }

        return result[m - 1][n - 1] + 1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    sol.shortestPathBinaryMatrix(grid);
}