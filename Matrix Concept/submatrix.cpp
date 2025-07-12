#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

string make_string(vector<int> arr) {
    string fs;
    for (int i = 0; i < arr.size(); i++) {
        if (i != arr.size() - 1) {
            fs += to_string(arr[i]) + " -> ";
        } else {
            fs += to_string(arr[i]);
        }
    }
    return fs;
}

class Solution {
   public:
    int countSubmatixWithSumK(vector<vector<int>> &grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for (int r = 0; r <= m; r++) {
            for (int c = 0; c <= n; c++) {
                for (int x = r; x < m; x++) {
                    for (int y = c; y < n; y++) {
                        cout << make_string({r, c, x, y}) << endl;
                    }
                    cout << endl;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    int k = 3;
    int target = 4;
    vector<vector<int>> grid = {
        {1, 1, 0},
        {1, 1, 0},
        {1, 1, 1},
    };
    int ans = sol.countSubmatixWithSumK(grid, k);
    cout << "ans --> " << ans << endl;
}