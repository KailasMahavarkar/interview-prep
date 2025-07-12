#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
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
// TC : O(n)
// SC : O(n)
class SolutionBruteforce {
   public:
    void solve(int n, int a, int b) {
        string distinctString = "";

        for (int i = 0; i < b; i++) {
            distinctString += (i + 'a');
        }

        int lenOfDistinctString = distinctString.size();
        int distinctStringCloneCount = (a / lenOfDistinctString);

        string cloneString = "";

        if (distinctStringCloneCount > 0) {
            while (cloneString.size() + lenOfDistinctString < n) {
                cloneString += distinctString;
            }
        }

        if (n - cloneString.size() > 0) {
            int diff = n - cloneString.size();
            cloneString += distinctString.substr(0, diff);
        }

        cout << cloneString << endl;
    }
};

// Approach-1 (cyclic pattern)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    void solve(int n, int a, int b) {
        string pattern = "";

        for (int i = 0; i < b; i++) {
            pattern += (char)(i + 'a');
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            result += pattern[i % b]; // <- this is game: creates a cyclic pattern
        }

        cout << result << endl;
    }
};

int main() {
    Solution sol;

    // int t;
    // cin >> t;

    // while (t--) {
    //     int n, a, b;
    //     cin >> n >> a >> b;
    //     sol.solve(n, a, b);
    // }

    sol.solve(5, 2, 2);
}