#include <algorithm>
#include <iostream>
using namespace std;

/*
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    int solve(int k, int l, int m, int n, int d) {
        if (k == 1 || l == 1 || m == 1 || n == 1) {
            return d;
        }

        if (min({k, l, m, n}) > d) {
            return 0;
        }

        int count = 0;
        for (int i = 1; i <= d; i++) {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    // int k, l, m, n, d;
    // cin >> k >> l >> m >> n >> d;

    int k = 10;
    int l = 9;
    int m = 8;
    int n = 7;
    int d = 6;

    Solution sol;
    int result = sol.solve(k, l, m, n, d);
    cout << result << endl;
    return 0;
}