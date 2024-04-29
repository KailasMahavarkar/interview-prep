#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int tribonacci(int n) {
        vector<int> fibo = {0, 1, 1};
        for (int i = 3; i <= n; i++) {
            fibo[i % 3] = fibo[0] + fibo[1] + fibo[2];
        }
        return fibo[n % 3];
    }
};

int main() {
    Solution sol;
    int ans = sol.tribonacci(5);
    cout << "ans --> " << ans << endl;
}