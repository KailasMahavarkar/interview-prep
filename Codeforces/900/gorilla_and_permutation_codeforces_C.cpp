#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// why we require this order?
// +---+---------------+----------------+------------------+
// | i |  Prefix       |  f(i) (≥ k)    |  g(i) (≤ m)      |
// +---+---------------+----------------+------------------+
// | 1 | [5]           | 5              | 0                |
// | 2 | [5,6]         | 5 + 6 = 11     | 0                |
// | 3 | [5,6,4]       | 11             | 0                |
// | 4 | [5,6,4,1]     | 11             | 1                |
// | 5 | [5,6,4,1,2]   | 11             | 1 + 2 = 3        |
// | 6 | [5,6,4,1,2,3] | 11             | 3 + 3 = 6        |
// +---+---------------+----------------+------------------+
// Sigma(f(i)) = 5 + 11 + 11 + 11 + 11 + 11 = 55
// Sigma(g(i)) = 0 + 0 + 0 + 1 + 3 + 6      = 10
// Difference = Sigma(f(i)) - Sigma(g(i))  = 55 - 10 = 45

// why not [5 6 4 1 2 3]??
// +---+---------------+----------------+------------------+
// | i |  Prefix       |  f(i) (≥ k)    |  g(i) (≤ m)      |
// +---+---------------+----------------+------------------+
// | 1 | [5]           | 5              | 0                |
// | 2 | [5,6]         | 5 + 6 = 11     | 0                |
// | 3 | [5,6,4]       | 11             | 0                |
// | 4 | [5,6,4,3]     | 11             | 3                |
// | 5 | [5,6,4,3,2]   | 11             | 3 + 2 = 5        |
// | 6 | [5,6,4,3,2,1] | 11             | 5 + 1 = 6        |
// +---+---------------+----------------+------------------+
// Sigma(f(i)) = 5 + 11 + 11 + 11 + 11 + 11 = 55
// Sigma(g(i)) = 0 + 0 + 0 + 3 + 5 + 6      = 10
// Difference = Sigma(f(i)) - Sigma(g(i))  = 55 - 14 = 41

// Observation:
// Thus, to maximize the difference,
// numbers >= k should be as early as possible
// numbers <= k should be as late as possible.

class Solution {
   public:
    void solve(int n, int m, int k) {
        vector<int> permutation;

        for (int num = n; num > m; num--) {
            cout << num << " ";
        }

        for (int num = 1; num <= m; ++num) {
            cout << num << " ";
        }

        for (auto &x : permutation) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Solution sol;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        sol.solve(n, m, k);
    }

    // Solution sol;
    // sol.solve(10, 3, 8);

    return 0;
}
