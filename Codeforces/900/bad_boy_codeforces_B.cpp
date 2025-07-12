#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
typedef long long ll;
using namespace std;

// Approach to the question:
// Deductions were on points... i was able to figure out the max distance anton 
// has to travel is corner... if you draw mxn matrix... and place (i,j) riley throwing
// two yoyo... you will notice... if anton had two pick one yoyo it will be the farthest 
// distance... but what about two... its also the farthest distance
// since then anthon have to travel from one end to another

// Learnings from question:
// My initial deductions to problem were correct but had one flaw
// i considered only 2 distances... like
// Initial  -> yoyo1
// Initial  -> yoyo2
// I missed a point where you have to travel from yoyo1 to yoyo2
// so the answer is:
// sum of all mahattan_distance()
// i.e inital_to_yoyo1 + yoyo1_to_yoyo2 + yoyo2_to_inital


class Solution {
   public:
    void solve(ll n, ll m, ll i, ll j) {
        vector<pair<ll, ll>> corners = {{1, 1}, {1, m}, {n, 1}, {n, m}};
        pair<ll, ll> farthest1, farthest2;
        ll max_distance = -1;

        for (auto &c1 : corners) {
            for (auto &c2 : corners) {
                ll inital_to_yoyo1 = abs(c1.first - i) + abs(c1.second - j);  // anton to yoyo-1
                ll yoyo1_to_yoyo2 = abs(c2.first - c1.first) + abs(c2.second - c1.second);
                ll yoyo2_to_inital = abs(c2.first - i) + abs(c2.second - j);
                ll distance = inital_to_yoyo1 + yoyo1_to_yoyo2 + yoyo2_to_inital;

                if (distance > max_distance) {
                    max_distance = distance;
                    farthest1 = c1;
                    farthest2 = c2;
                }
            }
        }

        cout << farthest1.first << " " << farthest1.second << " "
             << farthest2.first << " " << farthest2.second << endl;
    }
};

int main() {
    ll T = 1;
    cin >> T;
    Solution sol;

    while (T--) {
        ll n, m, i, j;
        cin >> n >> m >> i >> j;
        sol.solve(n, m, i, j);
    }
}