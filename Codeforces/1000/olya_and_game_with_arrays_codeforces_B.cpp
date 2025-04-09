#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Lets t
//     [1001, 7, 1007, 5]
//     [8, 11, 6]
//     [2, 9]

class Solution {
   public:
    vector<ll> getFirstAndSecondSmallest(vector<ll>& arr) {
        ll min1 = INT_MAX, min2 = INT_MAX;
        for (ll x : arr) {
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }

        return {min1, min2};
    }

    void solve(vector<vector<ll>>& arrays) {
        ll global_min = INT_MAX;
        vector<ll> seconds;

        for (vector<ll>& arr : arrays) {
            vector<ll> findRes = getFirstAndSecondSmallest(arr);
            ll firstSmallest = findRes[0];
            ll secondSmallest = findRes[1];
            global_min = min(global_min, firstSmallest);
            seconds.push_back(secondSmallest);
        }

        ll second_sum = accumulate(seconds.begin(), seconds.end(), 0LL);
        ll min_second = *min_element(seconds.begin(), seconds.end());
        cout << second_sum - min_second + global_min << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vector<ll>> arrays(n);
        for (ll i = 0; i < n; ++i) {
            ll m;
            cin >> m;
            arrays[i].resize(m);
            for (ll j = 0; j < m; ++j) {
                cin >> arrays[i][j];
            }
        }

        Solution sol;
        sol.solve(arrays);
    }

    // vector<vector<ll>> arr = {
    //     {1001, 7, 1007, 5},
    //     {8, 11, 6},
    //     {2, 9}};
    // Solution sol;
    // sol.solve(arr);

    return 0;
}
