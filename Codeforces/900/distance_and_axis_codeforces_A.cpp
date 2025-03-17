#include <bits/stdc++.h>
using namespace std;

// n -> starting point of line
// k -> required absolute difference
// ||B - 0| - |B - n|| = k
// ||B| - |B - n| = k

// lets rewrite with better naming
// |dist(0,B) − dist(Start,B) | = Diff
// we want to find minimum number of moves takes for us to adjust value of B such that
// |dist(0,B) − dist(Start,B) | is equal to Diff

// now if we substitute B as X
// ||x - 0| - |x - 22|| = 4
// such a equation is solvable if x is 13
// ||13 - 0| - |13 - 22|| = 4
// ||13| - | - 9| = 4
// | 13 - 9 | = 4
// 4 = 4

class Solution {
   public:
    void solve(int n, int k) {
        // when we say n >= k ... think n being too far ahead
        // k - n will result in -ve in such case

        // [diff(k)                         start(n)]
        if (n >= k) {
            // when n - k is even ... such a 'B' will always exists
            // which satifies the equation -> thus max 0 move

            // when n - k is odd (bruh it can never be odd) why?
            // |​(start − B) − ( B − 0)​| = diff
            // |start - 2B| = diff
            // start - diff = 2B
            // start - diff is multiple of 2*B.... so odd case will never exists
            // thats why we need to make it even first by doing +1 or -1 (which will take 1 move)
            cout << (n - k) % 2 << endl;
        }
        // when we say n < k
        // [start(k)                         diff(n)]
        else {
            cout << k - n << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        sol.solve(n, k);
    }

    return 0;
}
