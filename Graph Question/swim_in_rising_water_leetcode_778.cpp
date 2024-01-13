#include <bits/stdc++.h>
using namespace std;

/*
    Given an integer elevation matrix, rain falls, at time t, depth everywhere is t
    Can swim iff elevation at most t, return least time get from top left to bottom right

    Hint: At every step, find lowest water level to move forward

    Time: O(n^2 log n)
    Space: O(n^2)
*/

typedef pair<int, pair<int, int>> ppi;

class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<bool>> visited(N, vector<bool>(N));
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y];
        };

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto temp = pq.top();
            int waterLevel = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            pq.pop();

            if (x == N - 1 && y == N - 1) {
                return waterLevel;
            }

            for (auto& dir : directions) {
                int _x = x + dir[0];
                int _y = y + dir[1];

                if (isSafe(_x, _y)) {
                    pq.push({max(grid[_x][_y], waterLevel), {_x, _y}});
                    visited[_x][_y] = true;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    cout << sol.swimInWater(grid) << endl;

    return 0;
}