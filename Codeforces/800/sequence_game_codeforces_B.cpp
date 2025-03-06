#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    void solve(int n, ll arr[]) {
        vector<ll> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                ans.push_back(1);
            }
            ans.push_back(arr[i]);
        }

        cout << ans.size() << endl;
        for (auto itr : ans)
            cout << itr << " ";
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T = 1;
    cin >> T;

    Solution sol;

    while (T--) {
        ll n;
        cin >> n;

        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sol.solve(n, arr);
    }
}