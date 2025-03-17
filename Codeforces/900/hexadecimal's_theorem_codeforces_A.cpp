#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// MOST GREEDY SOLUTION EVER
// I came up with solution of this saying
// Fibo(x) = Fibo(a) + Fibo(b) + Fibo(0)
// and i was trying to find two numbers

// greedy misleads... i was able to narrow down to per say
// we dont need 'c' but i failed to narrow down further
// its stupidly insane... you dont need 'b' terms as well
// fibo(x) = fibo(x) + fibo(0) + fibo(0) is always valid

class Solution {
   public:
    void solve(int n) {
        cout << n << " 0 0" << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    sol.solve(n);
    return 0;
}
