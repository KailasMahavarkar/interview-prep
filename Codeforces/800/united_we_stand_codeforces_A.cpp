#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n, vector<int>& a) {
        unordered_set<int> b, c;
        sort(a.begin(), a.end());

        // intuition 1: incorrect
        //    using divisibility check (but ye complicated ya impossible hoga) but base intuition yahi hogi sabki
        //    -> ye question bad question ke category me daal do.. cuz ye anti-intuition follow karta h
        //
        // intuition 2: correct
        //    lets say [a, b, c, d, e, e, e] -> sorted numbers h
        //    -> assume karlo 'e' sabse bada h
        //    -> question ke rule ke according... tum ye bol sakte ho
        //    -> jitna bada number 'c' array me hoga.. utne chote numbers 'b' array me valid honge
        //    -> so max numbers seperate karo
        //    -> unclear?
        //    -> max number ko ek group me add karne se ye guranteed hoga...
        //       koi number b group me aa hi nahi sakta jo 'max' se divide ho sake
        //       isse dono groups non-empty honge... jo ye question ko indirectly solve karta h
        //    -> array [a, b, c, d, e] and [e, e, e]

        int maxx = *max_element(a.begin(), a.end());

        vector<int> groupA;
        vector<int> groupB;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == maxx) {
                groupB.push_back(a[i]);
            } else {
                groupA.push_back(a[i]);
            }
        }

        if (groupA.empty() || groupB.empty()) {
            cout << "-1" << endl;
            return;
        }

        cout << groupA.size() << " " << groupB.size() << endl;
        for (int x : groupA) cout << x << " ";
        cout << endl;
        for (int x : groupB) cout << x << " ";
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    Solution sol;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sol.solve(n, a);
    }

    // Solution sol;
    // vector<pair<int, vector<int>>> testCases = {
    //     {5, {1, 2, 3, 4, 5}},
    //     {3, {10, 20, 30}}};

    // for (auto& [n, a] : testCases) {
    //     sol.solve(n, a);
    // }
    return 0;
}
