#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printDP(vector<vector<int>> &dp) {
    for (auto &x : dp) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

class Solution {
   public:
    vector<vector<int>> dp;
    int knapSackHelper(int n, int w, int val[], int wt[]) {
        if (n == 0 || w == 0) {
            return 0;
        }

        if (dp[n][w] != -1) {
            return dp[n][w];
        }

        // if last element weight is more than current possible weight
        if (wt[n - 1] <= w) {
            int pick = val[n - 1] + knapSackHelper(n, w - wt[n - 1], val, wt);
            int unpick = knapSackHelper(n - 1, w, val, wt);
            dp[n][w] = max(pick, unpick);
        } else {
            dp[n][w] = knapSackHelper(n - 1, w, val, wt);
        }

        return dp[n][w];
    }
    int knapSack(int N, int W, int val[], int wt[]) {
        dp.resize(N + 1, vector<int>(W + 1, -1));
        int ans = knapSackHelper(N, W, val, wt);
        printDP(dp);
        return ans;
    }
};

int main() {
    int n = 4;
    int w = 8;
    int wt[4] = {1, 3, 4, 5};
    int val[4] = {1, 4, 5, 7};

    Solution sol;
    int ans = sol.knapSack(n, w, val, wt);
    cout << "ans: " << ans << endl;
}