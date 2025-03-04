#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(int k, int r) {
        for (int i = 1; i < 10; i++) {
            int price = k * i;
            if (price % 10 == 0 || (price % 10 == r)) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    // int k, r;
    // cin >> k >> r;

    int k = 237;
    int r = 7;

    Solution sol;
    int result = sol.solve(k, r);
    cout << result << endl;

    return 0;
}
