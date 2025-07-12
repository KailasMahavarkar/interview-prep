#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#define ll long long int
using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = arr[0];
    for (int i = 1; i < n; i++) {
        ans = (ans & arr[i]);
    }

    cout << ans << endl;
}

int main() {
    ll T = 1;
    cin >> T;

    while (T--) {
        solve();
    }
}