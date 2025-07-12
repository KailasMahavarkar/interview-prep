#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef long long ll;

class Solution {
   public:
    ll gcd(ll a, ll b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
    ll lcm(ll a, ll b) {
        return (a * b) / gcd(a, b);
    }
    void solve(ll a, ll b) {
        // required to avoid overflow
        // since (a * b) for two large number can cross long long limit
        if (b % a == 0) {
            // if a divides b, i.e., b = k × a .... (i)

            // what if that number we want to find is multiple of 'b' ?
            // x = k × b
            //   = (b / a) × b  <- replace k as (b / a) from (i)
            //   = b² / a
            cout << (b / a) * b << endl;
        } else {
            cout << lcm(a, b) << endl;
        }
    }
};

int main() {
    Solution sol;
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        ll a, b;
        cin >> a >> b;
        sol.solve(a, b);
    }

    // sol.solve(250000000, 500000000);
    return 0;
}
