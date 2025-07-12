#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/set-matrix-zeroes/description/
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
    int m;
    int n;

    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<bool> rowState(m + 1, false);
        vector<bool> colState(n + 1, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (!rowState[i]) {
                        rowState[i] = true;
                    }

                    if (!colState[j]) {
                        colState[j] = true;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowState[i] || colState[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> arr = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};

    Solution sol;
    sol.setZeroes(arr);
}