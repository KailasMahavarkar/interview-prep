#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
    Company Tags   : FAANG
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Greedy)
// TC : O(n)
// SC : O(1)

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // case [8, 2, 4]
        // we start from i as 1
        // 1st iter [2 - 8] = -6 | dont take it
        // 2nd iter [4 - 2] = 2  | take it
        for (int i = 1; i < prices.size(); i++) {
            int diff = (prices[i] - prices[i - 1]);
            if (diff > 0) {
                profit += diff;
            }
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {3, 2, 1, 0};
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout << "ans is " << ans << endl;
}