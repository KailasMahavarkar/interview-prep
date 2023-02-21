#include <bits/stdc++.h>
#include "C:/lib/helper.cpp"
using namespace std;

#define MOD 1000000007

int solve(long long nStairs, int i){
    if (i == nStairs)
        return 1;

    if (i > nStairs)
        return 0;

    return (solve(nStairs, i+1) + solve(nStairs, i+2)) % MOD;
    
}


int main(){
    int n = 14;
    vector<int> dp(n+1, -1);

    printVector("dp" ,dp);

    cout << "answer --> " << dp[n] << endl;
}