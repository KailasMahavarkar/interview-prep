#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n, int k) {
        // n = 10  k = 5
        // [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        if (n % k == 0) {
            cout << 1 << endl;
            return;
        }
        // n = 5, k = 10
        // [a1, a2, a3, a4, a5] -> each element should be atleast (n/k)
        else if (k % n == 0) {
            cout << (k / n) << endl;
            return;
        }
        // n = 6, k = 4
        // [x, x, x, x, x, x]
        // [1, 1, 1, 1, 2, 2]
        else if (n > k) {
            cout << 2 << endl;
        }
        // n = 3, k = 7
        // [x, x, x]
        // we already checked if k%n is 0...so we know for sure k/n will leave some reminder
        // (k / n) != 0 and will never be divisible by n
        // [(k/n) + (k/n) + (k/n)] = n
        // [(7/2) + (7/2) + (7/2)] = n
        // [2 + 2 + 2] = 7 ? so we need 1 extra step
        // [2 + 2 + (2 + 1) ] = n [works]
        else {
            cout << (k / n) + 1 << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    // int t;
    // cin >> t;

    // while (t--) {
    //     long long n, k;
    //     cin >> n >> k;
    //     sol.solve(n, k);
    // }

    sol.solve(1, 5);
    sol.solve(4, 3);
    sol.solve(8, 8);
    sol.solve(8, 17);

    return 0;
}
