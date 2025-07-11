#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
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

// Method 1: (tabulation) bottom-up
class Solution {
   public:
    int result = 0;
    vector<vector<int>> dp;
  
    string printShortestCommonSubsequence(string S1, string S2, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // base case
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        // choice diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S1[i - 1] == S2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        string lcs = "";
        int i = n;
        int j = m;
        while (i > 0 && j > 0) {
            if (S1[i - 1] == S2[j - 1]) {
                lcs += S1[i - 1];
                i--, j--;
            } else {
    
                if (dp[i][j - 1] > dp[i - 1][j]){
                    lcs.push_back(S2[j - 1]);
                    j--;
                }
                else{
                    lcs.push_back(S1[i - 1]);
                    i--;
                }
            }
        }

        while(i > 0){
            lcs.push_back(S1[i - 1]);
            i--;
        }

        while(j > 0){
            lcs.push_back(S2[j - 1]);
            j--;
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

int main() {
    string s1 = "ABC";
    string s2 = "ACB";

    int n = s1.length();
    int m = s2.length();

    Solution sol;
    string ans = sol.printShortestCommonSubsequence(s1, s2, n, m);

    cout << ans << endl;
    return 0;
}