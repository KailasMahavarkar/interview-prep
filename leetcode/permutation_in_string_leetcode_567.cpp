#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        // set of 26 characters
        int m[26] = {0};
        
        // array of character count of s1
        for (char c: s1){
            m[c - 'a']++;
        }

        int i = 0;
        int j = 0;
        int total = s1.size();
        
        // both i and j are run only O(n) times
        // j is forward pointer
        while (j < s2.size()){
            if (m[s2.at(j++) - 'a']-- > 0){
                total--;
            }

            if (total == 0) {
                return true;
            }

            // shifting of window
            if (j - i == s1.size() && m[s2.at(i++) - 'a']++ >= 0){
                total++;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    bool ans = sol.checkInclusion("ab", "bccba");
    cout << boolalpha << ans << endl; 
}