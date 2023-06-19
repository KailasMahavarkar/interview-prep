#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> dp;
    int knapsackHelper(int w, vector<int> &wt, vector<int> &val, int n) {
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
        if (wt[n] > w) {
            dp[n][w] = knapsackHelper(w, wt, val, n - 1);
        } else {
            int pickCase = val[n - 1] + knapsackHelper(w - wt[n - 1], wt, val, n - 1);
            int unpickCase = knapsackHelper(w, wt, val, n - 1);
            dp[n][w] = max(pickCase, unpickCase);
        }

        return dp[n][w];
    }
    int minCost(int n, vector<int> &cuts) {
        vector<int> values(n, 0);
        int total = 0;
        for (int i = 0; i < n; i++) {
            values[i] = i;
            total += i;
        }
        return knapsackHelper(total, cuts, values, n);
    }
};

int main() {
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    Solution sol;
    
    cout << minCost(n, cuts) << endl;
}