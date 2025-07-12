#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printDP(string msg, vector<vector<bool>> &dp) {
    cout << msg << " " << endl;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
   Time Complexity: O(N *X).
   Space Complexity:O(N * X).
   Where 'N' is the size of the array and 'X' is the target sum.
*/

int numberOfWays(int i, int sum, int n, vector<int> &num, vector<vector<int>> &dp) {
    // Not a valid case as sum becomes greater than what we want.
    if (sum < 0) {
        return 0;
    }

    // If we traverse the whole array.
    if (i == n) {
        // Sum becomes equal to the target sum.
        if (sum == 0) {
            return 1;
        }
        return 0;
    }

    // Return the value if we already have calculated.
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    // If we take the ith element.
    int pick = numberOfWays(i + 1, sum - num[i], n, num, dp);
    // If we do not take the ith element.
    int unpick = numberOfWays(i + 1, sum, n, num, dp);

    // Store the answer in dp and then return.
    dp[i][sum] = pick + unpick;
    return dp[i][sum];
}

int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return numberOfWays(0, tar, n, num, dp);
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    cout << "The number of subsets found are " << findWays(arr, k);
}