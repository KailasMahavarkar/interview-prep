#include <bits/stdc++.h>
using namespace std;

class SolutionBruteforce {
   public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b) * b);
    }

    void solve(int x) {
        for (int i = x; i > 0; i--) {
            for (int j = x; j > 0; j--) {
                if (gcd(i, j) + lcm(i, j) == x) {
                    cout << i << " " << j << endl;
                    return;
                }
            }
        }
    }
};

class Solution {
   public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b) * b);
    }

    void solve(int x) {
        // concept:
        // LCM(1, x) -> x
        // GCD(1, x) -> 1
        // LCM(x, x) -> x
        // GCD(x, x) -> x

        // so if number is even we can just divide it by 2 and sum it up to get same number
        if (x % 2 == 0) {
            // lcm(x / 2, x / 2) + gcd(x / 2, x / 2)  -> x
            cout << x / 2 << " " << x / 2 << endl;
        }

        // if number is odd we can make of 2 rules
        // LCM(1, x) -> x
        // GCD(1, x) -> 1
        // but we takeaway 1 from gcd(1, x) -> 1 then we need to have 1 number less in lcm
        if (x % 2 == 1) {
            cout << x - 1 << " " << 1 << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        Solution sol;
        sol.solve(x);
    }

    return 0;
}
