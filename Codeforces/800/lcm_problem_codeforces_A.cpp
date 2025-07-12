#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Steps taken to reach solution
// Observation:
// LCM(2, 3) -> 6
// LCM(2, 4) -> 4   (x, 2x) -> 2x
// LCM(2, 5) -> 10
// LCM(2, 6) -> 6   (x, 3x) -> 3x
// LCM(2, 7) -> 14
// LCM(2, 8) -> 8   (x, 4x) -> 4x

// Reading Question and Dedude facts:
// So i can say... LCM(l, n*l) -> n*l
// but we know 
// l <= LCM(l, n*l) <= r
// so we can deduce 
// n*l <= r
// n can be any natural number... starting from 2
// finally we can say, 2*l <= r

// Use this Input/Output since codeforces have wrong Output... but code passes for following output
// Input
// 4
// 1 1337
// 13 69
// 2 4
// 88 89
// Output
// 1 2
// 13 26
// 2 4
// -1 -1

class Solution {
   public:
    void solve(int l, int r) {
        if (2 * l <= r) {
            cout << l << " " << 2 * l << endl;
        } else {
            cout << "-1 -1" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        Solution sol;
        sol.solve(l, r);
    }
    return 0;
}