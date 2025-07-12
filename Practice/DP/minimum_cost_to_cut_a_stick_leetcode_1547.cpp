#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printDP(vector<vector<int>> &dp) {
    for (auto &x : dp) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

class Solution {
   public:
    vector<vector<int>> dp;
    int solve(int prices, int cuts, int n, int L) {
        if (n == 0 || L == 0){
            return 0;
        }

    }
    int minCost(int n, vector<int> &cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();


        dp.resize(m, vector<int>(m, -1));
        int ans = solve(cuts, 0, m - 1);
        printDP(dp);
        return ans;
    }
};