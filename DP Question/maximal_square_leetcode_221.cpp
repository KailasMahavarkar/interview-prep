#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/maximal-square/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal -> dp)
// TC : O(rows * cols)
// SC : O(rows * cols)

// Question: can we avoid (i != 0 && j != 0) check?
// We can avoid this condition if we do bound check conditionally later
// for{i->0 to rows}
//    for(j->0 to cols)
//       isSafe(i, j-1) ? t[i][j-1]: 0;

// Question: what if we do loop like (i->1 to rows) will this still work?
// NO, it will throw out of bound error while accessing 
// for{i->1 to rows}
//    for(j->1 to cols)


class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int side = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> t(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                t[i][j] = matrix[i][j] - '0';
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1' && i != 0 && j != 0) {
                    t[i][j] = 1 + min({t[i][j - 1], t[i - 1][j], t[i - 1][j - 1]});
                }
                side = max(side, t[i][j]);
            }
        }

        return side * side;
    }
};

int main() {
    vector<vector<char>> arr = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    Solution sol;
    int ans = sol.maximalSquare(arr);
    cout << "ans -->" << ans << endl;
}