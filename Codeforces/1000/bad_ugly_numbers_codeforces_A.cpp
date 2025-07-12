#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n) {
        if (n == 1) {
            cout << -1 << endl;
        } else {
            cout << 5;
            for (int i = 1; i < n; i++) {
                cout << 7;
            }
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
    // sol.solve(10);
    while (t--) {
        int n;
        cin >> n;
        sol.solve(n);
    }

    return 0;
}
