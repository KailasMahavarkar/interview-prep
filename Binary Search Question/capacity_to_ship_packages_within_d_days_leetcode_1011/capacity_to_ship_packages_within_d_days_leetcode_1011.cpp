#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : None
    Problem Link   : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(nlogw)
// SC : O(1)
class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        // guess the value of k -> (A->B) within D days
        int s = 1;
        int e = accumulate(weights.begin(), weights.end(), 0);

        // for (int i = s; i < e; i++) {
        //     if (canPlace(weights, days, i)) {
        //         return i;
        //     }
        // }

        // while (s < e) {
        //     int possibleK = s + (e - s) / 2;

        //     if (canPlace(weights, days, possibleK)) {
        //         e = possibleK;
        //     } else {
        //         s = possibleK + 1;
        //     }
        // }

        return e;
    }

   private:
    bool canPlace(vector<int>& weights, int days, int k) {
        int daysRequired = 1;
        int currentWeightSum = 0;

        for (int i = 0; i < weights.size(); i++) {
            // weights[i] -> 3
            // k = 1
            if (k < weights[i]) {
                return false;
            }

            if (currentWeightSum + weights[i] <= k) {
                currentWeightSum += weights[i];
            } else {
                daysRequired++;
                currentWeightSum = weights[i];
            }

            if (daysRequired > days) {
                return false;
            }
        }

        return daysRequired <= days;
    }
};

int main() {
    vector<int> weights = {2, 4, 6, 8, 10};
    int days = 2;
    Solution sol;
    int answer = sol.shipWithinDays(weights, days);
    cout << "min container size should be " << answer << endl;
}
