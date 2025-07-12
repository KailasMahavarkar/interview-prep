#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n, const vector<int>& s) {
        if (n == 1) {
            cout << -1 << endl;
            return;
        }

        vector<int> result;
        int start = 0;

        for (int i = 1; i <= n; i++) {
            // Check if we're at the end of a group (different size or end of array)
            if (i == n || s[i] != s[i - 1]) {
                int groupSize = i - start;

                // If any group has only 1 student, impossible
                if (groupSize == 1) {
                    cout << -1 << endl;
                    return;
                }

                // Add last student of group first, then all others
                result.push_back(i);
                for (int j = start; j < i - 1; j++) {
                    result.push_back(j + 1);  // Other students (1-indexed)
                }

                start = i;  // Start of next group
            }
        }

        // Output result
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    // sol.solve(7, {2, 2, 3, 3, 3, 4, 4});

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        sol.solve(n, s);
    }

    return 0;
}
