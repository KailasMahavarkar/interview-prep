#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &cost,  int n){
        if (n == 0)
            return cost[0];
        
        if (n == 1)
            return cost[1];

        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }

    int solve2(vector<int> &cost, vector<int> &dp, int n){
        if (n == 0)
            return cost[0];
        
        if (n == 1)
            return cost[1];

        if (dp[n] != -1)
            return dp[n];

        dp[n] = cost[n] + min(solve2(cost, dp, n-1), solve2(cost, dp, n-2));
        return dp[n];
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size() + 1, -1); 
        return solve2(cost, dp, n);
    }
};

int main(){
    vector<int> cost = {10, 15, 20};
    Solution sol;
    int ans = sol.minCostClimbingStairs(cost);
    cout << "ans -->" << ans;    
}