#include <iostream>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(long long n, long long m) {
        if (n == 1) {
            // [100]
            // -> difference is always 0
            cout << 0 << endl;
        } else if (n == 2) {
            // [0, 100]
            // -> difference is always highest number m
            cout << m << endl;
        } else {
            // n = 5 | m = 11
            // [0, 11, 0, 0, 0]
            //   11  11  0  0    -> 22

            //  [3, 0, 3, 0, 4]
            //     3  3  3  4    -> 13

            // n = 5 | m = 10
            //  [5, 0, 5, 0, 0]
            //    5   5  5  0    -> 15
            //
            //  [0, 5, 0, 5, 0]
            //     5  5  5  5    -> 20

            // both cases we can see 2*m as highest answer
            cout << 2 * m << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;
        Solution sol;
        sol.solve(n, m);
    }

    // Solution sol;
    // sol.solve(2, 2);
    return 0;
}
