#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(int n, vector<int>& a, vector<int>& b) {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {a[i], b[i]};
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            cout << v[i].first << ' ';
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << v[i].second << ' ';
        }
        cout << endl;
    };
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        Solution sol;
        sol.solve(n, a, b);
    }

    return 0;
}