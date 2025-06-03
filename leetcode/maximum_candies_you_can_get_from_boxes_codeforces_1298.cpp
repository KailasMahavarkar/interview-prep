#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : None
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    int maxCandies(
        vector<int>& status,
        vector<int>& candies,
        vector<vector<int>>& keys,
        vector<vector<int>>& containedBoxes,
        vector<int>& initialBoxes) {
        int totalCandies = 0;
        int n = status.size();

        queue<int> canOpen;
        set<int> hasBox;
        set<int> hasKey;

        for (int box : initialBoxes) {
            hasBox.insert(box);
            if (status[box] == 1) {
                canOpen.push(box);
            }
        }

        while (!canOpen.empty()) {
            int currentBox = canOpen.front();
            canOpen.pop();

            totalCandies += candies[currentBox];

            for (int key : keys[currentBox]) {
                hasKey.insert(key);

                if (hasBox.count(key) && status[key] == 0) {
                    status[key] = 1;
                    canOpen.push(key);
                }
            }

            for (int box : containedBoxes[currentBox]) {
                if (!hasBox.count(box)) {
                    hasBox.insert(box);

                    if (status[box] == 1 || hasKey.count(box)) {
                        if (status[box] == 0) {
                            status[box] = 1;
                        }
                        canOpen.push(box);
                    }
                }
            }
        }

        return totalCandies;
    }
};

int main() {
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};
    vector<vector<int>> keys = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes = {0};

    Solution sol;
    int result = sol.maxCandies(
        status,
        candies,
        keys,
        containedBoxes,
        initialBoxes);

    cout << "Total candies: " << result << endl;

    return 0;
}