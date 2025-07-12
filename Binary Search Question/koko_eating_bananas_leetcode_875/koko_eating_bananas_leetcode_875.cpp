#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/koko-eating-bananas/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Linear Search)
// TC : O(n * len(piles))
// SC : O(1)
class SolutionBruteforce {
   public:
    bool canEat(vector<int>& piles, int maxHour, int k) {
        int hour = 0;

        for (auto pile : piles) {
            hour += (pile / k);

            // hour = 8
            // k = 3
            if (pile % k != 0) {
                hour += 1;
            }

            if (hour > maxHour) {
                return false;
            }
        }

        return hour <= maxHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());

        for (int i = s; i < e; i++) {
            if (canEat(piles, h, i)) {
                return i;
            }
        }

        return e;
    }
};

class Solution {
   public:
    bool canEat(vector<int>& piles, int maxHour, int k) {
        int hour = 0;

        for (auto pile : piles) {
            hour += (pile / k);

            // hour = 8
            // k = 3
            if (pile % k != 0) {
                hour += 1;
            }

            if (hour > maxHour) {
                return false;
            }
        }

        return hour <= maxHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());

        for (int i = s; i < e; i++) {
            if (canEat(piles, h, i)) {
                return i;
            }
        }

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (canEat(piles, h, mid)) {  // binary search on answer
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return e;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    Solution sol;
    int answer = sol.minEatingSpeed(piles, h);
    cout << "minEatingSpeed koko must have is: " << answer << endl;
    return 0;
}