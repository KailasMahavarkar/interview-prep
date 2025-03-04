#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(string w) {
        if (w.size() == 1) {
            cout << w[0] << endl;
            return;
        }
        if (w.size() == 2) {
            cout << 'i' << endl;
            return;
        }
        cout << w.substr(0, w.size() - 2) + 'i' << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string w;
        cin >> w;
        Solution sol;
        sol.solve(w);
    }

    // Solution sol;
    // sol.solve("dus");

    return 0;
}
