#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : None
    Problem Link   : https://leetcode.com/problems/separate-squares-i/description/
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
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 1e9, high = -1e9;

        for (auto& sq : squares) {
            double x = sq[0], y = sq[1], l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double left = low, right = high;
        for (int i = 0; i < 100; ++i) {
            double mid = (left + right) / 2.0;
            double areaBelow = 0;

            for (auto& sq : squares) {
                double y = sq[1], l = sq[2];
                if (mid <= y) {
                    // Entire square is above the line
                    continue;
                } else if (mid >= y + l) {
                    // Entire square is below the line
                    areaBelow += l * l;
                } else {
                    // Line cuts through the square
                    double h = mid - y;  // height below the line
                    areaBelow += l * h;
                }
            }

            if (areaBelow < (totalArea / 2.0)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

int main() {
    vector<vector<int>> squares = {{0, 0, 2}, {1, 1, 1}};
    Solution sol;
    double ans = sol.separateSquares(squares);
    cout << "ans --> " << ans << endl;
}