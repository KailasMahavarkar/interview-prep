#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link  : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
    Company Tags  : goldmansachs
    references    : codestorywithmik
*/

// Approach-1 ()
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1Size = word1.size();
        int word2Size = word2.size();

        int i = 0;
        int j = 0;

        int w1i = 0;
        int w2i = 0;

        while (i < word1Size && j < word1Size) {
            if (word1[w1i][i] != word2[w2i][j]) {
                return false;
            }

            i++;
            j++;

            if (i == word1[w1i].size()) {
                i = 0;
                w1i++;
            }
            if (j == word2[w2i].size()) {
                j = 0;
                w2i++;
            }

            if (w1i == word1.size() && w2i == word2.size()) {
                return true;
            }

            return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> word1 = {"ab", "cde"};
    vector<string> word2 = {"abcde"};

    bool ans = sol.arrayStringsAreEqual(word1, word2);
    cout << boolalpha << "ans: " << ans << endl;
}