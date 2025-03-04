#include <iostream>
using namespace std;

class Solution {
   public:
    void solve(long long n, long long m) {
        if (n == 1) {
            // [100]
            // -> difference is always 0
            cout << 0 << endl;
        } 
        else if (n == 2){
            // [0, 100]
            // -> difference is always highest number m
            cout << m << endl;
        }
        else {
            // n = 5 | m = 11
            // [0, 11, 0, 0, 0]
            // --11--11--0--0--
            // difference sum is 22 which is highest possible
            // so its 2*m
            cout << 2 * m << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;
        Solution sol;
        sol.solve(n, m);
    }

    // Solution sol;
    // sol.solve(2, 2);
    return 0;
}
