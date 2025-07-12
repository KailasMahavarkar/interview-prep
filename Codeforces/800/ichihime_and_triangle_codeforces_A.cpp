#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int a, int b, int c, int d) {
        // x = b (kyunki a ≤ x ≤ [b]) -> choose b
        // y = c (kyunki b ≤ y ≤ [c]) -> choose c
        // z = c (kyunki [c] ≤ z ≤ d) -> choose c
        // b + c > c  -> triangle is valid as long we choose b + c > c (length of two sides is more than third)
        cout << b << " " << c << " " << c << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Solution sol;
        sol.solve(a, b, c, d);
    }
    return 0;
}
