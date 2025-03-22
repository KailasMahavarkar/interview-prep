#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
   public:
    void solve(int n) {
        ll k = 9;

        for (ll i = 0; i < n; i++) {
            if (i == 0) {
                cout << k;
                k--;
            } else {
                cout << k;
                k++;
            }

            if (k == 10) k = 0;
        }
        cout << endl;
    }
};

int main() {
    int t, n;
    cin >> t;

    Solution sol;

    while (t--) {
        cin >> n;
        sol.solve(n);
    }

    return 0;
}
