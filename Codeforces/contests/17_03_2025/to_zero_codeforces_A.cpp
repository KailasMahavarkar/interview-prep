#include <bits/stdc++.h>
using namespace std;

/*
    Problem Name   : A. To Zero
    Problem Link   : https://codeforces.com/contest/2075/problem/A
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

class Solution {
   public:
    int solve(int n, int k) {
        if (n <= k) return 1;

        // directly using ceil method
        // if (n % 2 == 0) {
        //     return ceil((double)n / (k - 1));
        // } else {
        //     return 1 + ceil((double)(n - k) / (k - 1));
        // }

        // using (n + k - 1) / k ... method of finding ceil
        if (n % 2 == 0) {
            return (n + k - 2) / (k - 1);
        } else {
            int remaining = n - k;
            return 1 + (remaining + k - 2) / (k - 1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution solution;
        cout << solution.solve(n, k) << "\n";
    }

    return 0;
}