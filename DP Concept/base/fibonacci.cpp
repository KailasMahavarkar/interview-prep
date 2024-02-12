#include <bits/stdc++.h>
using namespace std;

class SolutionNormal {
   public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class SolutionMemo {
   public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int a = 0;
        int b = 1;
        int c;

        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};

int main() {
    SolutionMemo s;
    cout << s.fib(10) << endl;
    return 0;
}