#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    int solve(string s) {
        vector<bool> seen(26, false);
        int uniq = 0;

        for (int i = 1; i < s.size() - 1; i++) {
            // a, b, c, d, e
            if (s[i] == ' ' || s[i] == ',') {
                continue;
            } else {
                int c = s[i] - 'a';
                if (!seen[c]) {
                    seen[c] = true;
                    uniq++;
                }
            }
        }

        return uniq;
    }
};

int main() {
    string s;
    getline(cin, s);

    // for testing
    // string s = "{a, b, c, a, b}";

    Solution sol;
    int result = sol.solve(s);
    cout << result << endl;

    return 0;
}