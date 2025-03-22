#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
   public:
    void solve(int n) {
        ll k = 9;

        // i = 0 | k = 9
        // print 9
        // decrement k

        // i = 1 | k = 8
        // print 8
        // increment k

        // i = 2 | k = 9
        // print 9
        // increment k

        // i = 3 | k = 10
        // reset k = 0

        // i = 4 | k = 0
        // print 0
        // increment k

        // i = 5 | k = 1
        // print 1
        // increment k...

        // i = 6 | k = 2
        // print 2
        // increment k...

        // pattern as: 989012....

        for (ll i = 0; i < n; i++) {
            if (i == 0) {
                cout << k;
                k--;
            } else {
                cout << k;
                k++;
            }

            if (k == 10) k = 0;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        sol.solve(n);
    }

    // sol.solve(30);

    return 0;
}
