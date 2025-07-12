#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();     // row
        int n = matrix[0].size();  // col

        int dir = 0;

        /*
            dir = 0: left -> right
            dir = 1: top -> down
            dir = 2: right -> left
            dir = 3: down -> top
        */

        vector<int> result;

        while (top <= down && left <= right) {
            if (dir == 0) {
                // left -> right
                // constant: row (top)

                for (int i = left, i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }

            if (dir == 1) {
                // top -> down
                // constant: col (right)

                for (int i = top, i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            if (dir == 2) {
                // right -> left
                // constant: row (down)

                for (int i = right, i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }

            if (dir == 3) {
                // down --> top
                // constant: col (left)

                for (int i = down, i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            dir++;

            if (dir == 4) {
                dir = 0;
            }
        }
    }
};

int main() {
}