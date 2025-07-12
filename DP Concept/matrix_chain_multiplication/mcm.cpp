#include <algorithm>
#include <climits>
#include <cstring>
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

// Approach 1: recursion + memoization
class SolutionMemo {
   public:
    int global_min = INT_MAX;
    int dp[101][101];
    int solve(int arr[], int i, int j) {
        if (i >= j) {
            return dp[i][j] = 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int local_min = INT_MAX;

        for (int k = i; k < j; k++) {
            int leftHalf = solve(arr, i, k);
            int rightHalf = solve(arr, k + 1, j);
            int current_cost = arr[i - 1] * arr[k] * arr[j];
            local_min = min(leftHalf + rightHalf + current_cost, local_min);
        }

        dp[i][j] = local_min;
        return local_min;
    }

    int matrixMultiplication(int N, int arr[]) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, N - 1);
    }
};

// Approach 1: bottom-up
class Solution {
   public:
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

        // Initialize the base cases
        for (int i = 1; i < N; i++) {
            dp[i][i] = 0;
        }

        printDP("", dp);

        // Fill up the dp table using bottom-up approach
        // for (int len = 2; len <= N - 1; len++) {
        //     for (int i = 1; i <= N - len; i++) {
        //         int j = i + len - 1;
        //         dp[i][j] = INT_MAX;
        //         for (int k = i; k < j; k++) {
        //             dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
        //         }
        //     }
        // }
        return -1;
        // return dp[1][N - 1];
    }
};

int main() {
    int arr[5] = {40, 20, 30, 10, 30};
    Solution sol;
    int answer = sol.matrixMultiplication(5, arr);
    cout << "Minimum number of multiplications: " << answer << endl;
    return 0;
}
