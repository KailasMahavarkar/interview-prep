#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/burst-balloons/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    int m, n;
    vector<vector<int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
    vector<vector<int>> visited;
    bool isSafe(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (!isSafe(i, j)) {
            return 0;
        }

        int local_minimum = 0;

        for (auto dir : directions) {
            int _x = i + dir[0];
            int _y = j + dir[1];

            if (isSafe(_x, _y)) {
                local_minimum = grid[_x][_y] + min(local_minimum, solve(grid, _x, _y));
            }
        }
        return local_minimum;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return solve(grid, 0, 0);
    }
};

int main() {
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {8, 1, 1}};

    Solution sol;
    int ans = sol.cherryPickup(grid);
    cout << "ans --> " << ans << endl;
}
