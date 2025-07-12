#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(long long a, long long b) {
        // lets make good number first
        // a number is good if it is divible by (A*B)
        // x, y, z be 3 numbers
        // x + y = z (as per question)

        // a = 7, b = 11
        // let z be the good number
        // z = (x * y * 2) // why 2 -> to make numbers distinct(take example 13, 2) in case you want to know
        // z =  (7 * 11 * 2) = 154
        // a + b = (2*a*b)
        // a + b = 154
        // z = 154

        // lets make 1st nearly good number.. which should be divisible by a
        // ummm.. what number is divisible by a -> A itself
        // a = 7, b=b, c = 154

        // so what should be the 2nd good number
        // simple we know a + b = c
        // b = c - a
        // b = 154 - 7
        // b = 147
        // Note:
        // b will always be divible by a...
        // because a*b will always be divisible by a
        // b = (a*b) - a  ... will always take away multiple of a from (a*b)
        // thus b will be divisibe by a

        if (b == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            long long z = a * b;
            long long x = a;
            long long y = z - x;
            cout << x << " " << y << " " << z << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        long long A, B;
        cin >> A >> B;
        sol.solve(A, B);
    }

    // sol.solve(7, 11);

    return 0;
}
