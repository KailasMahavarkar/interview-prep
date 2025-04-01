#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : None
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
    void solve(string n) {
        // very clever intuition to solve this question
        // n = 1 -> 11
        // n = 2 -> 22
        // n = 5 -> 55
        // n = 10 ->  1001
        // n = 11 ->  1111
        // n = 20 ->  2002
        // n = 30 ->  3003
        // observe pattern
        // every even-length palindrome is first half's reverse
        // meaning n=11, n=20 can be validated like:
        // [11, 22, 33, 44, 55, 66, 77, 88, 99, 1001, 1111, 1221, 1331, 1441, 1551, 1661, 1771, 1881, 1991, 2002]
        //  1    2   3   4   5   6   7   8  9    10    11     12   13    14    15   16      17   18    19    20

        string r = n;
        reverse(r.begin(), r.end());

        string s3 = n + r;
        cout << s3 << endl;
    }
};

int main() {
    string n;
    cin >> n;

    Solution sol;
    sol.solve(n);

    // Solution sol;
    // sol.solve("30");

    return 0;
}