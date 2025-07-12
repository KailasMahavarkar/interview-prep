#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printDP(string msg, vector<vector<int>> &dp) {
    cout << msg << " " << endl;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// METHOD 1: Basic knapsack code
class SolutionRecursive {
   public:
    int knapsackHelper(int w, int wt[], int val[], int n) {
        // weight ya knapsack ki capacity hi na ho
        if (n == 0 || w == 0) {
            return 0;
        }

        // agar last weight jyada ho toh select nai kar sakte kuch bhi
        if (wt[n] > w) {
            return knapsackHelper(w, wt, val, n - 1);
        } else {
            // do option honge -> pick or dont pick item
            int pickCase = val[n - 1] + knapsackHelper(w - wt[n - 1], wt, val, n - 1);
            int unpickCase = knapsackHelper(w, wt, val, n - 1);
            return max(pickCase, unpickCase);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) {
        return knapsackHelper(W, wt, val, n);
    }
};

// METHOD 2: Basic knapsack code with memoization
class SolutionMemo {
   public:
    vector<vector<int>> dp;
    int knapsackHelper(int w, int wt[], int val[], int n) {
        // when capacity is zero
        // when 0 items for selection
        if (n == 0 || w == 0) {
            return 0;
        }

        // lookup in dp
        if (dp[n][w] != -1) {
            return dp[n][w];
        }

        // weight of item is more than current capacity
        if (wt[n-1] > w) {
            dp[n][w] = knapsackHelper(w, wt, val, n - 1);
        } else {
            int pickCase = val[n - 1] + knapsackHelper(w - wt[n - 1], wt, val, n - 1);
            int unpickCase = knapsackHelper(w, wt, val, n - 1);
            dp[n][w] = max(pickCase, unpickCase);
        }

        return dp[n][w];
    }
    int knapSack(int W, int wt[], int val[], int n) {
        dp.resize(n + 1, vector<int>(W + 1, -1));
        return knapsackHelper(W, wt, val, n);
    }
};

// Tabulation method
class Solution {
   public:
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        // fill 1st row and 1st column
        for (int j = 0; j < n + 1; j++) {
            dp[j][0] = 0;
        }
        for (int i = 0; i < W + 1; i++) {
            dp[0][i] = 0;
        }

        // printDP("before ", dp);
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                if (wt[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    int pickCase = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    int unpickCase = dp[i - 1][j];
                    dp[i][j] = max(pickCase, unpickCase);
                }
            }
        }

        // printDP("after ", dp);
        return dp[n][W];
    }
};

int main() {
    int n = 3;
    int capacity = 4;
    int weights[n] = {4, 5, 1};
    int values[n] = {1, 2, 3};

    int ans = Solution().knapSack(capacity, weights, values, n);
    cout << "ans: " << ans << endl;
}