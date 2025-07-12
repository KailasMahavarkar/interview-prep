#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
typedef long long ll;

/*
    Problem Name   : None
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(nlogn)
// SC : O(n)
class Solution {
   public:
    void solve(int n) {
        priority_queue<ll> pq;
        for (ll i = n; i >= 1; i--) {
            pq.push(i);
        }

        ll a, b, c;

        cout << 2 << endl;

        while (pq.size() > 1) {
            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();

            cout << a << " " << b << endl;
            c = a + b;

            if (c & 1) {
                c++;
            }
            c /= 2;
            pq.push(c);
        }
    }
};

int main() {
    int t;
    cin >> t;
    Solution sol;

    while(t--){
        int n;
        cin >> n;
        sol.solve(n);
    }

    return 0;
}