#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int max_profit = 0;
        // think for example [7, 1, 5]
        // if we buy at '7' -> our buy becomes 7
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                // we can buy at [1, 5]
                // 1st iteration we buy at 7 (new low price)
                // 2nd iteration we buy at 5 (still 1 is best)
                buy = prices[i];
            }

            int diff = prices[i] - buy;
            // 1st iteration difference is [1 - 7] = -6 | -ve thus 0 is best
            // 2nd iteration difference is [5 - 1] = 4
            // note: when 2nd iteration new buy was 1 not 7 (previous case)
            if (diff > max_profit) {
                max_profit = diff;
            }
        }
        return max_profit;
    }
};

int main() {
    vector<int> prices = {1, 4, 8, 10};
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout << "ans --> " << ans << endl;
}