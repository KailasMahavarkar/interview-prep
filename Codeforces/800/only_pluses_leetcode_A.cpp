#include <bits/stdc++.h>
using namespace std;

// 4
// 1 1337
// 13 69
// 2 4
// 88 89
// Output
// 1 2
// 13 26
// 2 4
// -1 -1
class Solution {
   public:
    void solve(int a, int b, int c) {
        for (int i = 0; i < 5; i++) {
            if (a <= b && a <= c) {
                ++a;
            }
            else if (b <= a && b <= c) {
                ++b;
            }
            else if (c <= a && c <= b) {
                ++c;
            }
        }
        cout << a * b * c << endl;
    };
};

int main() {
    // int t;
    // cin >> t;

    // while (t--) {
    //     int a, b, c;
    //     cin >> a >> b >> c;

    //     Solution sol;
    //     sol.solve(a, b, c);
    // }

    Solution sol;
    sol.solve(2, 3, 4);
    return 0;
}


