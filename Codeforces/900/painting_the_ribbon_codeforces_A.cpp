#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Example: n = 10 | m = 3 | k = 3
// Kailas turn (he wants to max diversify so paints like):
// [A, B, C, A, B, C, A, B, C, A]

// Question:
// Kitne parts aise h jo 'A' ya 1st color se represent nahi ho sakte?
// otherwords:
// non_A_parts = (N - count_of_A)

// [1]      [2]      [3]      [4]
//  |        |        |        |
// [A, B, C, A, B, C, A, B, C, A]

// v =  (n / m)
// v =  (10 / 3)          v = 3
// v += (10 % 3 != 0)     v = 3 + 1 -> 4
// '4' ka meaning ye h... 4 parts aise h jo 'A' se painted h
// So, Shweta ke paas agar (n - v) moves chahiye to make them same color
// (n - v) -> represents all colors other than 'A'

// Verdict:
// confusing question + hard intuition

class Solution {
   public:
    void solve(int n, int m, int k) {
        int v = n / m;

        if (n % m) {
            v += 1;
        };

        int differentColors = (n - v);

        if (differentColors > k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;

    Solution sol;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        sol.solve(n, m, k);
    }

    return 0;
}
