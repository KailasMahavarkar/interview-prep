#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/hand-of-straights/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize) {
            return false;
        }

        map<int, int> hmap;

        for (int i = 0; i < hand.size(); i++) {
            hmap[hand[i]]++;
        }

        while (!hmap.empty()) {
            int curr = hmap.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                if (hmap[curr + i] == 0) {
                    return false;
                }

                hmap[curr + i]--;
                if (hmap[curr + i] < 1) {
                    hmap.erase(curr + i);
                }
            }
        }

        return true;
    }
};
int main() {
    vector<int> arr = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    Solution sol;
    bool ans = sol.isNStraightHand(arr, 3);
    cout << "ans --> " << ans << endl;
}