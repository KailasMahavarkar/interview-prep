#include <iostream>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n) {
        int k = n / 3;
        int x = n % 3;

        int a, b, c;

        if (x == 2) {
            a = k + 1;
            b = k + 2;
            c = k - 1;
        } else if (x == 1) {
            a = k;
            b = k + 2;
            c = k - 1;
        } else {
            a = k;
            b = k + 1;
            c = k - 1;
        }

        cout << a << " " << b << " " << c << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution sol;
        sol.solve(n);
    }
    return 0;
}
