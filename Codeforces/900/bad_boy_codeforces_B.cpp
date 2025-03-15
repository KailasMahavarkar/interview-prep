#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
   public:
    void solve(ll n, ll m, ll i, ll j) {
        vector<pair<ll, ll>> corners = {{1, 1}, {1, m}, {n, 1}, {n, m}};
        pair<ll, ll> farthest1, farthest2;
        ll max_distance = -1;

        for (auto &c1 : corners) {
            for (auto &c2 : corners) {
                ll inital_to_yoyo1 = abs(c1.first - i) + abs(c1.second - j);  // anton to yoyo-1
                ll yoyo1_to_yoyo2 = abs(c2.first - c1.first) + abs(c2.second - c1.second);
                ll yoyo2_to_inital = abs(c2.first - i) + abs(c2.second - j);
                ll distance = inital_to_yoyo1 + yoyo1_to_yoyo2 + yoyo2_to_inital;

                if (distance > max_distance) {
                    max_distance = distance;
                    farthest1 = c1;
                    farthest2 = c2;
                }
            }
        }

        cout << farthest1.first << " " << farthest1.second << " "
             << farthest2.first << " " << farthest2.second << endl;
    }
};

int main() {
    ll T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        ll n, m, i, j;
        cin >> n >> m >> i >> j;
        sol.solve(n, m, i, j);
    }
}