#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
#define ll long long

// best solution is always to flip the 2nd panel on time t=8
// this makes sure adjecent left and right panel will be at 9
// 0 0 0 0 0 0 0
// 0 8 0 0 0 0 0  <- flip 2nd panel at t=8
// 9 8 9 0 0 0 0  <- t = 9  [adjacent panels will be flipped to 9]
// 9 8 9 0 0 0 0  <- t = 10 [panel adjacent to 9 will increment to 10 -> but is 0 (due to recurring loop)]
//       |
//    this stays 0 why? 9 + 1 = 10 -> becomes 0 (recurring loop)
// 9 8 9 0 1 0 0  <- t = 11
// 9 8 9 0 1 2 0  <- t = 12
// 9 8 9 0 1 2 3  <- t = 13

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
    // int t, n;
    // cin >> t;

    // while (t--) {
    //     cin >> n;
    //     sol.solve(n);
    // }

    for (int i = 0; i < 10; i++) {
        sol.solve(i);
    }

    return 0;
}
