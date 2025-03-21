#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : B. Permutation Sort (Educational Codeforces Round 109 (Rated for Div. 2))
    Problem Link   : https://codeforces.com/problemset/problem/1525/B
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// 0 moves: everything is sorted
// [1, 2, 3, 4, 5]

// 1 moves:
//  1  2  3  4 ...  n
// [1, x, y, z ..., n]
// when 0th and last index are same... we only need 1 move

// 1 moves:
//  1  2  3  .....  n
// [_, _, _, ....., n] <- n is already fixed so 1 move
// or
//  1  2  3  4 ...  n
// [1, _, _, n ..., k] <- 1 is already fixed so 1 move
// when 1th index OR last index is same (only 1 move is required)

// 2 moves:
//  1  2  3  4 ...  n
// [_, 1, _, n ..., k] <- move 1: fix 1 first
// [1, n, _, _ ..., k] <- move 2: fix n next
// [1, _, _, _ ..., n] :)

// 3 moves:
//  1  2  3  4 ...  n
// [n, _, _, _ ..., 1] <- move 1: sort[1:n]
// [n, 1, _, _, .....] <- move 2: sort[1:2]
// [1, n, _, _, .....] <- move 3: sort[1:n]
// [1, _, _, _, .., n] :)

class Solution {
   public:
    void solve(vector<int> &arr) {
        int n = arr.size();

        // 0 moves -> already sorted
        if (is_sorted(arr.begin(), arr.end())) {
            cout << "0" << endl;
            return;
        }

        // 3 moves -> worst case
        if (arr[0] == n && arr[n - 1] == 1) {
            cout << "3" << endl;
            return;
        }

        // 1 moves -> middle array is unsorted
        if (arr[0] == 1 && arr[n - 1] == n) {
            
            cout << "1" << endl;
            return;
        }

        // 1 moves -> one of the end is sorted
        if (arr[0] == 1 || arr[n - 1] == n) {
            cout << "1" << endl;
            return;
        }

        // any other case we need 2 moves
        cout << "2" << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        Solution().solve(a);
    }

    return 0;
}