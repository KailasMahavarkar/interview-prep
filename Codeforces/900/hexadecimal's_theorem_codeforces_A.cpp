#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef long long ll;

// MOST GREEDY SOLUTION EVER
// I came up with solution of this saying
// Fibo(x) = Fibo(a) + Fibo(b) + Fibo(0)
// and i was trying to find two numbers

// greedy misleads... i was able to narrow down 
// Fibo(x) = Fibo(a) + Fibo(b) + Fibo(0)
// we dont need 'b' terms as well (my intuition half failed)
// its stupidly insane
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
