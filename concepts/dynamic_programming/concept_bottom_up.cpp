#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 14;
    vector<int> dp(n+1, -1);

    dp[1] = 1;
    dp[0] = 0;

    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    printVector("dp" ,dp);

    cout << "answer --> " << dp[n] << endl;
}