#include <algorithm>
#include <iostream>
using namespace std;

/*
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class SolutionBruteForce {
   public:
    int solve(int k, int l, int m, int n, int d) {
        if (k == 1 || l == 1 || m == 1 || n == 1) {
            return d;
        }

        if (min({k, l, m, n}) > d) {
            return 0;
        }

        int count = 0;
        for (int i = 1; i <= d; i++) {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
                count++;
            }
        }
        return count;
    }
};

// Approach-2 (Inclusion-Exclusion Principle)
// TC : O(1)
// SC : O(1)
class Solution {
   public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;  // Prevent overflow
    }

    int solve(int k, int l, int m, int n, int d) {
        int A1 = (d / k) + (d / l) + (d / m) + (d / n);
        int A2 = (d / lcm(k, l)) + (d / lcm(k, m)) + (d / lcm(k, n)) +
                 (d / lcm(l, m)) + (d / lcm(l, n)) + (d / lcm(m, n));
        int A3 = (d / lcm(lcm(k, l), m)) + (d / lcm(lcm(k, l), n)) +
                 (d / lcm(lcm(k, m), n)) + (d / lcm(lcm(l, m), n));
        int A4 = d / lcm(lcm(k, l), lcm(m, n));

        return A1 - A2 + A3 - A4;
    }
};

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    // int k = 2, l = 3, m = 4, n = 5, d = 24;
    Solution sol;
    int result = sol.solve(k, l, m, n, d);
    cout << result << endl;
    return 0;
}