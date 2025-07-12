#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool solve(string a, string b) {
        if (a.length() > b.length()) {
            return solve(b, a);
        }

        if (b.length() - a.length() == 0) {
            return a == b;
        }

        int ai = 0;
        int aj = a.size() - 1;

        int bi = 0;
        int bj = b.size() - 1;
        int minLen = min(a.size(), b.size());

        while (ai < minLen && bi < minLen && a[ai] == b[bi]) {
            ai++;
            bi++;
        }

        while (aj > 0 && bj > 0 && a[aj] == b[bj]) {
            aj--;
            bj--;
        }

        return ai > aj;  // ai overlapped
    }
};

int main() {
    string a = "The boy is nice.";
    string b = "The girl is nice.";
    Solution sol;
    bool ans = sol.solve(a, b);
    cout << "ans --> " << boolalpha << ans << endl;
}


// Given two strings s1 and s2, find out if they only differ by the insertion of a phrase.
// Example 1:
// The boy goes to the hospital
// The cute little boy goes to the hospital
// 'cute litte' is the added phrase everything else is the same so return True

// Example 2:
// The boy is nice.
// The girl is nice.
// -> Return False