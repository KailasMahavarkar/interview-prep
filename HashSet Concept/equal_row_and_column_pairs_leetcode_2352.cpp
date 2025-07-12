#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int>, int> hmap;

        // row wise traversal
        for (int row = 0; row < n; row++) {
            // check if entire row {3, 2, 1} in hmap
            hmap[grid[row]]++;
        }

        int counter = 0;

        // col wise traversal
        for (int col = 0; col < n; col++) {
            vector<int> temp;
            for (int row = 0; row < n; row++) {
                temp.push_back(grid[row][col]);
            }
            counter += hmap[temp];
        }

        return counter;
    }
};

int main() {
    vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    Solution sol;
    int ans = sol.equalPairs(grid);
    cout << "ans -->" << ans << endl;
}