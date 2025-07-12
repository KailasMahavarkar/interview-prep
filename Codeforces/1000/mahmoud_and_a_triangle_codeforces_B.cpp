#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
typedef long long ll;

/*
    Problem Name   : B. Mahmoud and a Triangle
    Problem Link   : https://codeforces.com/problemset/problem/766/B
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(nlogn)
// SC : O(1)
class Solution {
   public:
    void solve(vector<int> &segments) {
        int n = segments.size();
        sort(segments.begin(), segments.end());

        for (ll i = 0; i < n - 2; ++i) {
            ll x = segments[i];
            ll y = segments[i + 1];
            ll z = segments[i + 2];
            if (x + y > z) {
                cout << "YES" << endl;
                return;
            }
        }

        cout << "NO" << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i];
    }
    Solution sol;
    sol.solve(segments);

    // vector<int> segments = {1, 5, 3, 2, 4};  // yes
    // Solution sol;
    // sol.solve(segments);
    return 0;
}
