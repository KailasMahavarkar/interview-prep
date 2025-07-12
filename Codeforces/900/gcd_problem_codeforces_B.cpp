#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n) {
        int c = 1;
        int a;
        int b;

        // STEP 1:
        // a + b + c = n
        // a + b = n - c
        // STEP 2:
        // a + b = n - 1
        // b = n - a - 1 ................ (1)

        // gcd(a, b) = c
        // gcd(a, b) = 1  ................(2)

        // we know a, b has to be coprime... to have gcd as 1 (since we set c = 1)
        // so, we bruteforce for every 'a' value we iterate we try to find gcd(i, b)
        // if the gcd's result is 1

        // its like asking
        // gcd(2, b) = 1 ...... will that give me 1
        // gcd(3, b) = 2 ...... will that give me 1
        // gcd(4, b) = 3 ...... will that give me 1
        // "b" also interally depends upon 'a' for calculation but that does not matter

        for (int a = 2; a <= n; a++) {
            // to have gcd(a, b) = 1 ... both a, b has to be coprime (cannot be even)
            if (a != 2 && a % 2 == 0) continue;

            int b = n - a - 1;
            int val = __gcd(a, b);
            if (val == 1) {
                cout << a << " " << b << " " << c << endl;
                return;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    // sol.solve(10);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        sol.solve(n);
    }

    return 0;
}

// for future reference why my intution failed:
// didn't work -> this question is special case of gcd
// GCD(x, y) -> 1 (when two numbers are co-prime) -> concept was unknown
// a + b + c = n
// a + b =  (N - gcd(a, b))
// (a + b) + gcd(a, b) = N
// (a + a) + gcd(a, a) = N
// we know gcd(x, x) -> x
// N = (a + a) + gcd(a, a)
// N = (a + a) + a
// N = 3a