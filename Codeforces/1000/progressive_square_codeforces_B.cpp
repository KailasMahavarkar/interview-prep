#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string solve(int n, int c, int d, vector<int>& b) {
        sort(b.begin(), b.end());
        int a11 = b[0];

        vector<int> expected;
        expected.reserve(n * n);

        for (int i = 0; i < n; ++i) {
            int base = a11 + i * c;
            for (int j = 0; j < n; ++j) {
                expected.push_back(base + j * d);
            }
        }

        sort(expected.begin(), expected.end());
        return expected == b ? "YES" : "NO";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Solution solution;

    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> b(n * n);
        for (int i = 0; i < n * n; ++i) {
            cin >> b[i];
        }

        cout << solution.solve(n, c, d, b) << '\n';
    }

    return 0;
}
