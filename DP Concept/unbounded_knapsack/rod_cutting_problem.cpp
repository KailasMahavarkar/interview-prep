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
    //    prices = {1, 5, 8, 9, 10, 17, 17, 20}
    //   lengths = {1, 2, 3, 4, 5, 6, 7 , 8}

    // values  = {1, 5, 8, 9, 10, 17}
    // weights = {1, 2, 3, 4, 5, 6}

    vector<vector<int>> dp;
    int cutRodSolve(int price[], int length[], int n, int L) {
        if (L == 0 || n == 0) {
            return 0;
        }

        if (dp[n][L] != -1) {
            return dp[n][L];
        }

        if (length[n - 1] <= L) {
            // variation is on 'n'
            //  since in unbounded we can choose same item again
            int cut = price[n - 1] + cutRodSolve(price, length, n, L - length[n - 1]);
            int nocut = cutRodSolve(price, length, n - 1, L);
            dp[n][L] = max(cut, nocut);
        } else {
            dp[n][L] = cutRodSolve(price, length, n - 1, L);
        }

        return dp[n][L];
    }
    int cutRod(int price[], int n) {
        int lengths[n];
        for (int i = 0; i < n; i++) {
            lengths[i] = i + 1;
        }

        int L = n;

        dp.resize(n + 1, vector<int>(n + 1, -1));
        int ans = cutRodSolve(price, lengths, n, L);
        // de-allocation
        dp.clear();

        return ans;
    }
};

int main() {
    int n = 7;
    int prices[n] = {1, 3, 4, 5};

    int ans = Solution().cutRod(prices, n);
    cout << "ans: " << ans << endl;
}