#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int xor_array(vector<int> &arr) {
        int result = 0;
        for (auto num : arr)
            result ^= num;
        return result;
    }

    void solve(vector<int> &arr) {
        int n = arr.size();

        // if n is even -> take xor of all elements
        if (n % 2 == 0) {
            cout << 2 << endl;
            cout << 1 << ' ' << n << endl;
            cout << 1 << ' ' << n << endl;
        } else {
            // [7, 1, 1, 9, 9, 0, 1]
            //  1  2  3  4  5  6  7  <- indexes

            // (2 -> 2) ka XOR karo
            // i,e 1 ^ 1 -> 0
            // new array becomes:
            // [7, 0, 1, 9, 9, 0, 1]
            //  1  2  3  4  5  6  7  <- indexes

            // (1 -> 2) ka xor
            // 7 ^ 0 -> 7
            // new array becomes
            // [7, 7, 1, 9, 9, 0, 1]
            //  1  2  3  4  5  6  7  <- indexes

            // (1 -> 2) ka xor
            // 7 ^ 7 -> 0
            // new array becomes
            // [0, 0, 1, 9, 9, 0, 1]
            //  1  2  3  4  5  6  7  <- indexes

            // (2 -> n) ka xor karo
            // 0 ^ 1 ^ 9 ^ 9 ^ 0 ^ 1 -> lets say K aya iska answer
            // [0, k, k, k, k, k, k]
            //  1  2  3  4  5  6  7  <- indexes

            // (2 -> n) ka xor karo
            // 2->n is always even -> iska XOR 0 hi ayega
            // [0, 0, 0, 0, 0, 0, 0]
            //  1  2  3  4  5  6  7  <- indexes

            cout << 5 << endl;
            cout << 2 << ' ' << 2 << endl;
            cout << 1 << ' ' << 2 << endl;
            cout << 1 << ' ' << 2 << endl;
            cout << 2 << ' ' << n << endl;
            cout << 2 << ' ' << n << endl;
        }
    }
};

int main() {
    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sol.solve(arr);
    }

    // vector<int> arr = {1, 5, 4, 1, 4};
    // sol.solve(arr);
    return 0;
}
