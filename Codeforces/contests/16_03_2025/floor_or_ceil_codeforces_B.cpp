#include <algorithm>
#include <iostream>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef long long ll;

ll computeMin(ll x, ll n, ll m) {
    x >>= n;
    x = (x + (1LL << m) - 1) >> m;
    return x;
}

ll computeMax(ll x, ll n, ll m) {
    x = (x + (1LL << m) - 1) >> m;
    x >>= n;
    return x;
}

int main() {
    cout << computeMax(12, 1, 2) << endl;
    cout << computeMin(12, 1, 2) << endl;

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--) {
    //     ll x, n, m;
    //     cin >> x >> n >> m;
    //     ll minVal = computeMin(x, n, m);
    //     ll maxVal = computeMax(x, n, m);
    //     cout << min(minVal, maxVal) << " " << max(minVal, maxVal) << "\n";
    // }

    return 0;
}