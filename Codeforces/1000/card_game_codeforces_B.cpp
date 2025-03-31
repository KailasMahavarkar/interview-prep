#include <iostream>
using namespace std;

class Solution {
   public:
    void solve(int a1, int a2, int b1, int b2) {
        int count = 0;
        if (wins(a1, a2, b1, b2)) count++;  // p1(a1,a2) vs p2(b1,b2)
        if (wins(a1, a2, b2, b1)) count++;  // p1(a1,a2) vs p2(b2,b1)
        if (wins(a2, a1, b1, b2)) count++;  // p1(a2,a1) vs p2(b1,b2)
        if (wins(a2, a1, b2, b1)) count++;  // p1(a2,a1) vs p2(b2,b1)
        cout << count << endl;
    }

   private:
    // win -> function ke rounds humesha (a1 -> b1) and (a2 -> b2) ke mapping pe hi hoga
    // it is the solve function in which are we controlling behaviour of this mapping
    bool wins(int a1, int a2, int b1, int b2) {
        int p1_wins = 0;
        int p2_wins = 0;

        if (a1 > b1) {
            p1_wins++;
        } else if (b1 > a1) {
            p2_wins++;
        }

        if (a2 > b2) {
            p1_wins++;
        } else if (b2 > a2) {
            p2_wins++;
        }
        return p1_wins > p2_wins;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        Solution sol;
        sol.solve(a1, a2, b1, b2);
    }

    // Solution sol;
    // sol.solve(1, 1, 10, 10);
    return 0;
}