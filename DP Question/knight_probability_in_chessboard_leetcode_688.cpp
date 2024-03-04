#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/knight-probability-in-chessboard/description/
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
    unordered_map<string, double> dp;
    vector<pair<int, int>> directions = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    double helper(int N, int K, int row, int col) {
        // K = 0 means... we are still in board
        // why? since ... out of bound condition protects us
        // meanining.... K moves have happened.. we didnt go out of bound.. thus we are withing board
        if (K == 0) {
            return 1.0;
        }

        string key = to_string(K) + "_" + to_string(row) + "_" + to_string(col);

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        double ans = 0;
        for (auto &dir : directions) {
            int x = row + dir.first;
            int y = col + dir.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                ans += helper(N, K - 1, x, y);
            }
        }

        return dp[key] = (ans / 8.0);
    }

    double knightProbability(int n, int k, int row, int column) {
        return helper(n, k, row, column);
    }
};

int main() {
    int n = 3, k = 2, row = 0, col = 0;
    Solution sol;
    double result = sol.knightProbability(n, k, row, col);
    cout << "ans --> " << result << endl;
}
