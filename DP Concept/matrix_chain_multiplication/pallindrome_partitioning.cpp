#include <bits/stdc++.h>
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

class SolutionMemo {
   public:
    vector<vector<int>> dp;
    bool isPallindrome(string str, int s, int e) {
        while (s <= e) {
            if (str[s] != str[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    int solve(string str, int i, int j) {
        // Base case 1
        if (i >= j) {
            return 0;
        }

        // Base case 2
        if (isPallindrome(str, i, j)) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int local_min = INT_MAX;

        // k has to go till j-1 reason is (k+1) will be wrong otherwise
        for (int k = i; k < j; k++) {
            int leftHalf = solve(str, i, k);
            int rightHalf = solve(str, k + 1, j);
            // 1 isliye since "KiK" pallindrome me 'K' already pallindrome hoga
            local_min = min(1 + leftHalf + rightHalf, local_min);
        }

        dp[i][j] = local_min;
        return local_min;
    }
    int palindromicPartition(string str) {
        int N = str.length();
        dp.resize(N + 1, vector<int>(N + 1, -1));
        return solve(str, 0, N - 1);
    }
};

class Solution {
   public:
    int palindromicPartition(string str) {
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (isPalindrome(str, i, j)) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }

    bool isPalindrome(string str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    string str = "ababbbabbababa";
    Solution sol;
    int ans = sol.palindromicPartition(str);
    cout << "ans --> " << ans << endl;
}