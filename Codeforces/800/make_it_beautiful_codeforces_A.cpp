#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

class Solution {
   public:
    void solve(ll n, vector<ll>& arr) {
        swap(arr[0], arr[1]);      // swap 1st and 2nd
        swap(arr[n - 1], arr[0]);  // swap first and last

        if (arr[0] == arr[1])  // if they match (we can never have answer)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << nline;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;

    Solution sol;

    while (T--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sol.solve(n, arr);
    }

    return 0;
}
