#include <iostream>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n, string &s) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '.') {
                int count = 0;
                
                while (i < n && s[i] == '.') {
                    count++;
                    i++;
                }

                if (count > 2) {
                    ans = 2;
                    break;
                } else {
                    ans += count;
                }
            }
        }

        cout << ans << endl;
    }
};

int main() {
    int t;
    cin >> t;
    Solution sol;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        sol.solve(n, s);
    }
    return 0;
}
