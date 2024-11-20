#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/longest-repeating-character-replacement/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
    Level          : Brilliant
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> fmap(26, 0);

        int l = 0;
        int mostFrequentCharacterCount = 0;
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            int rc = s[r] - 'A';
            int lc = s[l] - 'A';
            
            fmap[rc]++;
            mostFrequentCharacterCount = max(mostFrequentCharacterCount, fmap[rc]);
            int lettersToChange = (r - l + 1) - mostFrequentCharacterCount;

            if (lettersToChange > k) {
                fmap[lc]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

int main() {
    string s = "AAAABBBCCCAAA";
    int k = 3;
    Solution sol;
    int ans = sol.characterReplacement(s, k);
    cout << "ans --> " << ans << endl;
}