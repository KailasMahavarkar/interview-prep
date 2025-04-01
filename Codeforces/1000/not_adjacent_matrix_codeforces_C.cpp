#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
typedef long long ll;

// Approach-1 (Normal)
// TC : O(n*n)
// SC : O(n*n)
class SolutionComplex {
   public:
    void solve(int n) {
        // inutiton -> fill all evens then odds by count
        if (n == 1) {
            cout << "1" << endl;
            return;
        }

        if (n == 2) {
            cout << "-1" << endl;
            return;
        }

        vector<vector<int>> result(n, vector<int>(n, 0));

        int totalOddCount = (n * n) / 2 + (n % 2 == 1);
        int totalEvenCount = (n * n) / 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (totalEvenCount > 0) {
                    result[i][j] = (totalEvenCount * 2);
                    totalEvenCount--;
                } else if (totalOddCount > 0) {
                    result[i][j] = (totalOddCount * 2) - 1;
                    totalOddCount--;
                }
            }
        }

        for (auto &row : result) {
            for (auto &c : row) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
};

// Approach-2 (Optimal)
// TC : O(n*n)
// SC : O(1)
class Solution {
   public:
    void solve(int n) {
        if (n == 1) {
            cout << "1" << endl;
            return;
        }

        if (n == 2) {
            cout << "-1" << endl;
            return;
        }

        vector<vector<int>> result(n, vector<int>(n, 0));

        int odd = 1;
        int even = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (odd <= n * n) {
                    cout << odd << " ";
                    odd += 2;
                } else {
                    cout << even << " ";
                    even += 2;
                }
            }
            cout << endl;
        }
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
    // Solution sol;
    // sol.solve(3);

    return 0;
}
