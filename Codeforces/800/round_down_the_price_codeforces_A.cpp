#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef long long ll;

class SolutionBruteforce {
   public:
    void solve(int x, vector<ll> &powers) {
        if (x == 1) {
            cout << "0" << endl;
            return;
        }

        int s = 0, e = powers.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (powers[mid] <= x) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        cout << abs(powers[s - 1] - x) << endl;
    }
};

class Solution {
   public:
    void solve(int m) {
        ll val = 1;
        while (val * 10 <= m) {
            val *= 10;
        }

        cout << (m - val) << endl;
    }
};

double log_base(double x, double y) {
    return log(x) / log(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    vector<ll> powers;
    for (int i = 0; i <= 9; i++) {
        powers.push_back(pow(10, i));
    }

    // int t;
    // cin >> t;
    // while (t--) {
    //     int m;
    //     cin >> m;
    //     // sol.findPowerLessX(m, powers);
    //     sol.solve(m);
    // }

    // cout << ((int)log10(172132138)) << endl;
    cout << ((int)log_base(84, 2)) << endl;

    // sol.solve(1, powers);
    // for (int i = 0; i < powers.size(); i++) {
    //     cout << powers[i] << " ";
    // }
    // cout << endl;
    return 0;
}
