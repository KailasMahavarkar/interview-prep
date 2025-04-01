#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : A. Mahmoud and Longest Uncommon Subsequence
    Problem Link   : https://codeforces.com/problemset/problem/766/A
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(1)
// SC : O(1)
class Solution {
   public:
    void solve(string a, string b) {
        // question says if a == b ... both are same ... thus -1 we have to return why?
        // a and b are identical both are subsequence of each other

        // when a and b are not same
        // it is impossible to form subsequence of B -> A (by deleting chars from B to form A)
        // it is impossible to form subsequence of A -> B (by deleting chars from A to form B)

        // what about partial overlapping
        // a = "ab"
        // b = "abcd"

        // For "ab":
        // Subsequences are: "a", "b", "ab", ""
        
        // For "abce":
        // "a", "b", "ab", "ac", "ad", "bc", "bd", "cd", "abc", "abd", "acd", "bcd", "abcd", ""

        // longest common subsequence is "ab"
        // longest uncommon subsequence (which exist in a but not in b or viceversa)
        // why "abcd"??

        // For string A (subsequence which are in A but not in B)
        // -> NONE

        // For string B (subsequence which are in B but not in A) are:
        // "c" (length 1)
        // "d" (length 1)
        // "ac", "ad", "bc", "bd", "cd" (length 2)
        // "abc", "abd", "acd", "bcd" (length 3)
        // "abcd" (length 4)

        if (a == b) {
            cout << "-1" << endl;
        } else {
            cout << max(a.length(), b.length()) << endl;
        }
    }
};

int main() {
    string a, b;
    cin >> a >> b;

    Solution sol;
    sol.solve(a, b);

    return 0;
}
