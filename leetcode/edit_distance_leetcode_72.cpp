#include <bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>> dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
   public:
    vector<vector<int>> dp;
    int editDistance(string word1, string word2, int m, int n) {
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }

        if (dp[m - 1][n - 1] != -1) {
            return dp[m - 1][n - 1];
        }

        if (word1[m - 1] == word2[n - 1]) {
            return dp[m - 1][n - 1] = editDistance(word1, word2, m - 1, n - 1);
        }

        int insertResult = editDistance(word1, word2, m, n - 1);
        int deleteResult = editDistance(word1, word2, m - 1, n);
        int replaceResult = editDistance(word1, word2, m - 1, n - 1);
        return dp[m - 1][n - 1] = 1 + min(replaceResult, min(insertResult, deleteResult));
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        editDistance(word1, word2, word1.length(), word2.length());
        return dp[word1.length() - 1][word2.length() - 1];
    }
};

int main() {
    string word1 = "sea";
    string word2 = "eat";
    int ans = Solution().minDistance(word1, word2);
    cout << ans << endl;
    return 0;
}
