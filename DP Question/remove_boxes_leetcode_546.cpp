#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/remove-boxes/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O(n^3)
// SC : O(n^3)

class Solution {
   public:
    vector<int> boxes;
    int n;
    int dp[101][101][101];
    int solve(int i, int j, int extra) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j][extra] != -1) {
            return dp[i][j][extra];
        }

        // calculate count
        int count = 1;
        int nextOne = i + 1;

        while (nextOne <= j && boxes[nextOne - 1] == boxes[nextOne]) {
            count++;
            nextOne++;
        }

        // pick case -> we have extra + count
        int result = pow(count + extra, 2) + solve(nextOne, j, 0);

        // dont pick case
        for (int m = nextOne; m <= j; m++) {
            if (boxes[m] == boxes[i]) {
                result = max(result, solve(m, j, extra + count) + solve(nextOne, m - 1, 0));
            }
        }

        return dp[i][j][extra] = result;
    }

    int removeBoxes(vector<int>& boxes) {
        this->boxes = boxes;
        memset(dp, -1, sizeof(dp));
        return solve(0, boxes.size() - 1, 0);
    }
};

int main() {
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    Solution sol;
    int ans = sol.removeBoxes(boxes);
    cout << "ans --> " << ans << endl;
}