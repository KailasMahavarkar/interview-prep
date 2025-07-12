#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/furthest-building-you-can-reach/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(2^(ladder * bricks)) -> with Memo its O(ladder * bricks)
// SC : O(ladder * bricks)
class SolutionDP {
   public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& heights, int idx, int bricks, int ladders) {
        if (idx == n - 1) {
            return 0;
        }

        if (dp[bricks][ladders] != -1) {
            return dp[bricks][ladders];
        }

        // case 1
        if (heights[idx] >= heights[idx + 1]) {
            return 1 + solve(heights, idx + 1, bricks, ladders);
        }

        int brickAnswer = 0;
        int ladderAnswer = 0;

        // case 2 -> we use bricks only if we have bricks more than next building height
        if (bricks >= heights[idx + 1] - heights[idx]) {
            brickAnswer = 1 + solve(heights, idx + 1, bricks - (heights[idx + 1] - heights[idx]), ladders);
        }

        // case 3 -> we use ladders only if we have any ladders available
        if (ladders > 0) {
            ladderAnswer = 1 + solve(heights, idx + 1, bricks, ladders - 1);
        }

        return dp[bricks][ladders] = max(brickAnswer, ladderAnswer);
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();
        dp = vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1));
        return solve(heights, 0, bricks, ladders);
    }
};

// Approach-2 (lazy greedy) -> time travel -> restore past
// TC : O(nlog(n))
// SC : O(1)
class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i;
        for (i = 0; i < heights.size() - 1; i++) {
            if (heights[i] > heights[i + 1]) {
                continue;
            }

            // greedily use all bricks
            int diff = heights[i + 1] - heights[i];
            if (bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            } else if (ladders > 0) {
                if (!pq.empty()) {
                    // we can choose to use ladder right now or exchange that for bricks from past
                    int maximumBrickFromPast = pq.top();
                    if (maximumBrickFromPast >= diff) {
                        // exchange bricks for ladders
                        bricks += maximumBrickFromPast;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }

                ladders--;  // use used this in past or present
            } else {
                break;
            }
        }

        return i;
    }
};

int main() {
    vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    int bricks = 5;
    int ladders = 1;
    Solution sol;
    int ans = sol.furthestBuilding(heights, bricks, ladders);
    cout << "ans --> " << ans << endl;
}