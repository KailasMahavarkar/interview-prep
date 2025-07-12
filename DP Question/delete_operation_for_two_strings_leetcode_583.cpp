#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/delete-operation-for-two-strings/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : edit_distance_leetcode_72
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

using namespace std;

class Solution {
   public:
    int dp[501][501];
    int editDistance(string word1, string word2, int m, int n) {
        // when word2 is empty.. return remaining length of word1
        if (n == 0) {
            return m;
        }

        // when word1 is empty.. return remaining length of word2
        if (m == 0) {
            return n;
        }

        // check subproblem in dp
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        // when last char of strings are same just move your pointer
        if (word1[m - 1] == word2[n - 1]) {
            return dp[m][n] = editDistance(word1, word2, m - 1, n - 1);
        }
        int deleteFromWord1 = editDistance(word1, word2, m - 1, n);
        int deleteFromWord2 = editDistance(word1, word2, m, n - 1);
        return dp[m][n] = 1 + min({deleteFromWord1, deleteFromWord2});
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return editDistance(word1, word2, word1.length(), word2.length());
    }
};

int main() {
    string word1 = "DOG";
    string word2 = "DIG";
    Solution sol;
    int answer = sol.minDistance(word1, word2);
    cout << "answer --> " << answer << endl;
}