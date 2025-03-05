#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(int a, int b) {
        // a = 5
        // b = 2
        // [1, 1, 1, 1, 1, 2, 2]
        // but for every two 1's we need corresponding one 2
        // if sum is not even we can never negate them .... rule 1
        // if a == 0 and b % 2 is 1 .... we can again never negate them
        // why not check for b == 0 and a % 2 is 1?
        // --> question has given [a and b (0 <= a, b < 10)] -> a has <= 0 condition not b
        if ((a + 2 * b) % 2 != 0) {
            cout << "No" << endl;
            return;
        }

        if (a == 0 && b % 2 == 1) {
            cout << "No" << endl;
            return;
        }

        cout << "Yes" << endl;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution sol;
        sol.solve(a, b);
    }

    // Solution sol;
    // vector<vector<int>> ops = {
    //     {0, 1},
    //     {0, 3},
    //     {2, 0},
    //     {2, 3},
    //     {3, 1}};

    // for (int i = 0; i < ops.size(); i++) {
    //     sol.solve(ops[i][0], ops[i][1]);
    // }

    return 0;
}
