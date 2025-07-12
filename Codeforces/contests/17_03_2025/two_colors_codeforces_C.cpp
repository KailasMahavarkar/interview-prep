#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Name   : C. Two Colors 
    Problem Link   : https://codeforces.com/contest/2075/problem/C
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

class Solution {
   public:
    long long solve(int n, const vector<int>& capacities) {
        vector<int> freq(n + 1, 0);
        for (int cap : capacities) {
            freq[cap]++;
        }

        vector<int> F(n + 2, 0);
        F[n] = freq[n];
        for (int x = n - 1; x > 0; --x) {
            F[x] = F[x + 1] + freq[x];
        }

        long long ways = 0;
        for (int k = 1; k < n; ++k) {
            long long left_valid = F[k];
            long long right_valid = F[n - k];
            long long common = F[max(k, n - k)];
            ways += left_valid * right_valid - common;
        }
        return ways;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> capacities(m);
        for (int i = 0; i < m; ++i) {
            cin >> capacities[i];
        }

        Solution solution;
        cout << solution.solve(n, capacities) << "\n";
    }
    return 0;
}