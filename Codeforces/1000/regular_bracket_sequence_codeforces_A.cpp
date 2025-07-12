#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(string& s) {
        int n = s.size();
        if (n % 2) {
            cout << "NO";
        } else {
            if (s[0] == ')' || s[n - 1] == '(') {
                cout << "NO";
            } else {
                cout << "YES";
            }
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Solution sol;

    while (t--) {
        string s;
        cin >> s;
        sol.solve(s);
    }

    return 0;
}
