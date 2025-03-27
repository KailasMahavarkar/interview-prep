#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Imagine a garbage collector (gc) with initially inactive state (0 cost in incurred for wait once gc is active)
// initally we dont wakeup gc? why -> simple we have no cleanup active until 1st non-zero block is encountered
// goal of gc is to clean all space except last one (range is from 0 to n-1)
// gc has 2 modes -> active, inactive
// [0, 2, 0, 0, 2, 0]
//  i

// when i=0
// gc is still inactive ... cost is still 0

// when i=1
// gc is active now  ... cost += 2 -> cost = 2

// when i=2
// gc is still active ... cost += 1 (cost for waiting) -> cost = 3

// when i=3
// gc is still active ... cost += 1 (cost for waiting) -> cost = 4

// when i=4
// gc is still active ... cost += 2 -> cost = 6

// when i=5
// gc will not clean this memory

class Solution {
   public:
    void solve(vector<ll>& a) {
        ll n = a.size();

        ll sum = 0;
        bool ok = false;
        for (ll i = 0; i < n - 1; i++) {
            if (a[i]) ok = true;

            if (ok && a[i] == 0) {
                sum++;
            } else {
                sum += a[i];
            }
        }
        cout << sum << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sol.solve(a);
    }

    // vector<ll> arr = {0, 2, 0, 0, 2, 0};
    // sol.solve(arr);

    return 0;
}
