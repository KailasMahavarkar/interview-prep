#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

typedef long long ll;

class Solution {
   public:
    void solve(ll n, ll x, vector<pair<char, ll>>& operations) {
        ll icecreamCount = x;
        ll distressKidsCount = 0;

        for (int i = 0; i < operations.size(); i++) {
            pair<char, ll> p = operations[i];

            if (p.first == '-' && icecreamCount < p.second) {
                distressKidsCount++;
            }

            if (p.first == '-' && icecreamCount >= p.second) {
                icecreamCount -= p.second;
            }

            if (p.first == '+') {
                icecreamCount += p.second;
            }
        }

        cout << icecreamCount << " " << distressKidsCount << endl;
    }
};

int main() {
    // int n, x;
    // cin >> n >> x;
    // vector<pair<char, ll>> operations(n);

    // for (int i = 0; i < n; i++) {
    //     cin >> operations[i].first >> operations[i].second;
    // }

    // Solution sol;
    // sol.solve(n, x, operations);

    Solution sol;
    vector<pair<char, ll>> ops = {
        {'+', 5},
        {'-', 10},
        {'-', 20},
        {'+', 40},
        {'-', 20}};

    sol.solve(5, 7, ops);

    return 0;
}
