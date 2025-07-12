#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> mat(101, vector<double>(101, 0.0));
        mat[0][0] = (double)poured;
        for (int row = 0; row <= query_row; row++) {
            for (int col = 0; col <= query_glass; col++) {
                double extra = (mat[row][col] - 1.0) / 2.0;
                if (extra > 0) {
                    mat[row + 1][col] += extra;
                    mat[row + 1][col + 1] += extra;
                }
            }
        }

        return min(1.0, mat[query_row][query_glass]);
    }
};

int main() {
    Solution sol;
    double ans = sol.champagneTower(2, 1, 1);
    cout << "ans --> " << ans << endl;
}