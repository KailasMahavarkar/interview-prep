#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(int n) {
        n = n + 1;
        int spaces = n * 2 - 1;
        for (int i = 0; i < n - 1; i++) {
            for (int k = 0; k < spaces / 2; k++) {
                cout << "  ";
            }

            for (int j = 0; j < i; j++) {
                cout << j << " ";
            }

            for (int j = i; j >= 0; j--) {
                cout << j << (j == 0 ? "" : " ");
            }
            spaces = max(spaces - 2, 0);
            cout << endl;
        }

        spaces = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < spaces / 2; k++) {
                cout << "  ";
            }

            for (int j = 0; j < i; j++) {
                cout << j << " ";
            }

            for (int j = i; j >= 0; j--) {
                cout << j << (j == 0 ? "" : " ");
            }
            cout << endl;
            spaces += 2;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    Solution sol;
    sol.solve(n);
    // sol.solve(7);
    return 0;
}
