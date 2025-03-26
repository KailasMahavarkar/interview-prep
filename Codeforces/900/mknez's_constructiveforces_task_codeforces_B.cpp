#include <bits/stdc++.h>
using namespace std;

// for n = 3
// [-1, +1, -1] -> not possible
// why?
// take any two numbers... total sum is -1 but A[i] + A[i + 1] is 0
// there exists no solution for this

// for all evens
// [-1, +1, -1, +1 ..... ] will work always
// take any two numbers... total sum is 0 and A[i] + A[i + 1] is also 0

// for odds it requires special pattern obervation
// n = 5
// [-1, +1, -1, +1, -1] ... will fail total = -1  | A[i] + A[i+1] is 0

// applying i, i+1 logic
// let i = n = 5
// [5, -4, 5, -4, 5]    ... will fail total =  7  | A[i] + A[i+1] is 1

// our aim is to make A[i] + A[i+1] and total(sum) as same
// what if we take n/2 as i
// n = 5
// n/2 = 2
// i = 2 and i + 1 = 3

// [2, 3, 2, 3, 2]      ... will fail total >= A[i] + A[i+1] ... always
// [2, -3, 2, -3, 2]    ... will fail total = 0   | A[i] + A[i+1] is -1
// observation: keeping the first value as even will always result in total a 0 but A[i] + A[i+1] will be -1

// [-3, 2, -3, 2, -3]   ... will fail total = -5  | A[i] + A[i+1] is -1
// observation: keeping the first value as odd will always result in total a -ve but more than -1 but A[i] + A[i+1] will be -1

// clearly we are doing something wrong... this all fails
// n = 5
// n/2 = 2
// i = (n/2) - 1 and i + 1 = (n/2)
// i = 1 and i + 1 = 2

// [2, -1, 2, -1, 2]    ... will fail total = 4   | A[i] + A[i+1] is 1
// [1, -2, 1, -2, 1]    ... will pass total = -1  | A[i] + A[i+1] is -1
// why this works??
// when we want to keep total sum as minimal ... selecting A[i] = (n/2) - 1 and A[i+1] = (n/2) gurantees -1 sum
// next is we need to find pattern which will hold true for A[i] + A[i+1] = -1
// and only way to do it is if we arrange in -1 +1 pattern .. while making sure larger number has -ve value.

class Solution {
   public:
    void solve(int n) {
        if (n == 3) {
            cout << "NO" << endl;
            return;
        }

        cout << "YES" << endl;
        int summ = 0;

        if (n % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    cout << -1 << " ";
                } else {
                    cout << 1 << " ";
                }
            }
        } else {
            int _i = (n / 2) - 1;
            int _i_plus_1 = -1 * (n / 2);

            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    cout << _i << " ";
                    summ += _i;
                } else {
                    cout << _i_plus_1 << " ";
                    summ += _i_plus_1;
                }
            }
        }
        cout << endl;
        cout << summ;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    // sol.solve(5);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        sol.solve(n);
    }

    return 0;
}
