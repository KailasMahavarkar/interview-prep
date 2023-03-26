#include <bits/stdc++.h>
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
    long long int solve(int coins[], int N, int sum) {
    }
    long long int count(int coins[], int N, int sum) {
    }
};

int main() {
    int sum = 10;
    int N = 4;
    int coins[N] = {2, 5, 3, 6};

    Solution sol;
    long long int ans = sol.count(coins, N, sum);
    cout << "ans: " << ans << endl;
}