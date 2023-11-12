#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags                : Samsung
    GfG Link                    : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
*/

class Solution {
   public:
    vector<vector<int>> shortest_distance(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1)
                    grid[i][j] = 100000;
            }
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 100000)
                    grid[i][j] = -1;
            }
        }

        return grid;
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
    Solution sol;
    vector<vector<int>> answer = sol.shortest_distance(edges);

    for (auto& e : answer) {
        for (int i = 0; i < e.size(); i++) {
            cout << e[i] << " ";
        }
        cout << endl;
    }
}