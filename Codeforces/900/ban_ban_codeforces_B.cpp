#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    void solve(int n) {
        cout << (n / 2) + (n % 2) << endl;

        int i = 1;
        int j = 3 * n;

        while (i < j) {
            cout << i << " " << j << endl;
            i += 3;
            j -= 3;
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        sol.solve(n);
    }
    // sol.solve(3);
    return 0;
}
