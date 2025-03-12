#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

class Solution {
   public:
    void solve(int n, vector<int>& trace) {
        int idx = 0;
        string result = "";

        unordered_map<int, int> fmap;

        for (int i = 0; i < n; i++) {
            if (trace[i] == 0) {
                result += (idx + 'a');
                fmap[idx + 'a']++;
                idx++;
            } else {
                for (int j = 0; j < 26; j++) {
                    char c = 'a' + j;
                    if (fmap[c] == trace[i]) {
                        result += c;
                        fmap[c]++;
                        break;
                    }
                }
            }
        }

        cout << result << endl;
    }
};

int main() {
    Solution sol;
    // int t;
    // cin >> t;

    // while (t--) {
    //     int n;
    //     cin >> n;

    //     vector<int> trace(n);
    //     for (int i = 0; i < n; i++) {
    //         cin >> trace[i];
    //     }

    //     sol.solve(n, trace);
    // }

    // Example test case
    vector<int> trace = {0, 0, 0, 1, 0, 2, 0, 3, 1, 1, 4};
    sol.solve(11, trace);

    return 0;
}
