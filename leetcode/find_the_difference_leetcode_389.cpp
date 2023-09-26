#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    char findTheDifference(string s, string t) {
        int sumA = 0;
        int sumB = 0;

        // char will be [-1, -1, -1, 0] <- assumption
        for (char ch : s) {
            sumA += (ch - 'a');
        }

        // char will be [0, 0, 0, 1] <- since we are assuming 4th char was extra
        for (char ch : t) {
            sumB += (ch - 'a');
        }

        return (sumB - sumA) + 'a';
    }
};

int main() {
    Solution sol;
    char s = sol.findTheDifference("abcd", "abcde");
    cout << "diff --> " << s << endl;
}