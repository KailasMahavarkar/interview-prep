#include <bits/stdc++.h>
using namespace std;

/*
    Company Tags                : Samsung
    GfG Link                    : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
*/

class Solution {
   public:
    void shortest_distance(vector<vector<int>>& grid) {
        int n = grid.size();

        // mark -ve weight which represent unconnected as INT_MAX
        // since input is maximum 1000 ... we are taking 10000 as safer side
        // you can infact have INT_MAX as well
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    grid[i][j] = 10000;
                }
            }
        }

        // Floyd Warshall visit source from via node
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }

        // This step restores back values, since we are not returning anything
        // we are supposed to modify matrix in-place but since previously
        // we modified -1 to INT_MAX (or 10000) we need to reverse that
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 10000) {
                    grid[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
    Solution sol;
    sol.shortest_distance(edges);

    for (auto& e : edges) {
        for (int i = 0; i < e.size(); i++) {
            cout << e[i] << " ";
        }
        cout << endl;
    }
}