#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;


int fib(int n, vector<int> &dp){
    if (n <= 1){
        return n;
    }

    if (dp[n] != -1){
        return dp[n];
    }

    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main(){
    int n = 14;
    vector<int> dp(n+1, -1);

    int answer = fib(n, dp);
    cout << "answer --> " << answer << endl;
}