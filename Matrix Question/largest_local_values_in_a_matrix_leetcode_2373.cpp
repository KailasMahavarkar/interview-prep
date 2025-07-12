#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/largest-local-values-in-a-matrix/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(m*n*9)
// SC : O(m*n)
class Solution {
   public:
    int findLocalMax(vector<vector<int>>& grid, int row, int col) {
        int local_max = INT_MIN;
        for (int m = row; m <= row + 2; m++) {
            for (int n = col; n <= col + 2; n++) {
                local_max = max(local_max, grid[m][n]);
            }
        }
        return local_max;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> answer(n - 2, vector<int>(n - 2, 0));

        for (int row = 0; row < n - 2; row++) {
            for (int col = 0; col < n - 2; col++) {
                answer[row][col] = findLocalMax(grid, row, col);
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}};

    Solution sol;
    sol.largestLocal(grid);
}
