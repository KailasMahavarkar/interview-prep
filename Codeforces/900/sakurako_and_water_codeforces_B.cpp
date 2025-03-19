#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

// Approach-1 (Normal)
class Solution {
   public:
    void solve(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int answer = 0;

        for (int col = 0; col < n; col++) {
            // [x, y] -> represent [row, col]
            int i = 0;
            int j = col;

            int minVal = INT_MAX;
            // which ever breaks first we return
            while (i < m && j < n) {
                minVal = min(minVal, matrix[i][j]);
                i++;
                j++;
            }

            if (minVal < 0) {
                answer += abs(minVal);
            }
        }

        for (int row = 1; row < m; row++) {
            // [x, y] -> represent [row, col]
            int i = row;
            int j = 0;

            int minVal = INT_MAX;
            // which ever breaks first we return
            while (i < m && j < n) {
                minVal = min(minVal, matrix[i][j]);
                i++;
                j++;
            }

            if (minVal < 0) {
                answer += abs(minVal);
            }
        }

        cout << (answer == INT_MAX ? 0 : answer) << endl;
    }
};

int main() {
    Solution sol;
    int t;
    cin >> t;
    while (t--) {
        int line;
        cin >> line;

        vector<vector<int>> matrix(line, vector<int>(line));
        for (int i = 0; i < line; ++i) {
            for (int j = 0; j < line; ++j) {
                cin >> matrix[i][j];
            }
        }

        sol.solve(matrix);
    }

    // vector<vector<int>> matrix = {
    //     {1, 1, -1, -1, 3},
    //     {-3, 1, 4, 4, -4},
    //     {-1, -1, 3, 0, -5},
    //     {4, 5, 3, -3, -1},
    //     {3, 1, -3, -1, 5}};
    // sol.solve(matrix);

    return 0;
}
