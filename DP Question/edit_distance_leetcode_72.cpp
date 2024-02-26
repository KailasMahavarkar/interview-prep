#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/edit-distance/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : delete_operation_for_two_strings_leetcode_583
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> dp;
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
            dp[m][n] = editDistance(word1, word2, m - 1, n - 1);
        } else {
            // DO
            // DI
            // Insert on string one
            //          DOI
            //          DI
            // since last char matches we remove it and string becomes DO, D ... since
            // it caused 1 char from second string to be removed... we are doing (n-1)
            // indicating ... now our second string is reduced by 1

            int insertResult = editDistance(word1, word2, m, n - 1);
            int deleteResult = editDistance(word1, word2, m - 1, n);
            int replaceResult = editDistance(word1, word2, m - 1, n - 1);
            dp[m][n] = 1 + min({replaceResult, insertResult, deleteResult});
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        // initalize dp
        dp.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
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