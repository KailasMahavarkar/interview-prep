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

class Solution {
   public:
    int result = 0;
    vector<vector<int>> dp;
    int count = 0;
    int LCS(string text1, string text2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (text1[n - 1] == text2[m - 1]) {
            dp[n][m] = 1 + LCS(text1, text2, n - 1, m - 1);
        } else {
            dp[n][m] = max(LCS(text1, text2, n - 1, m), LCS(text1, text2, n, m - 1));
        }

        return dp[n][m];
    }
    int minOperations(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        dp.resize(n + 1, vector<int>(m + 1, -1));

        // logic -> (heap --> pea)
        // find LCS of heap and pea which is "ea"
        // here we can say h & p are basically deleted from STR1
        // later we can add p in LCS to give "pea"

        int lcsLength = LCS(str1, str2, n, m);
        int minDeleteSteps = (n - lcsLength); // heap(len 4) - ea(len 2) = 2
        int minInsertSteps = (m - lcsLength); // pea(len 3) - ea(len 2) = 1
        return minDeleteSteps + minInsertSteps;
    }
};
int main() {
    string s1 = "heap";
    string s2 = "pea";
    Solution sol;
    int ans = sol.minOperations(s1, s2);
    cout << "ans -->" << ans << endl;
}
