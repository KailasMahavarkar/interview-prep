#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int pathSum = 0;
        int prevLowestIndex = 0;

        // get the index of first lowest index
        for (int i = 0; i < rows; i++) {
            int firstLowest = INT_MAX;
            int secondLowest = INT_MAX;
            int firstLowestIndex = -1;
            int secondLowestIndex = -1;

            // get the index of first lowest index
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] < secondLowest) {
                    secondLowest = firstLowest;
                    secondLowestIndex = firstLowestIndex;
                    firstLowest = grid[i][j];
                    firstLowestIndex = j;
                }
            }

            swap(firstLowest, secondLowest);
            swap(firstLowestIndex, secondLowestIndex);

            cout << firstLowest << secondLowest << endl;
        }

        return pathSum;
    };
};

int main() {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution sol;
    int ans = sol.minFallingPathSum(grid);
    cout << "ans --> " << ans << endl;
}