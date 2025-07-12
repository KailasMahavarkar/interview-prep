#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/robot-collisions/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

typedef pair<int, pair<int, char>> ppc;

class Solution {
   public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        ppc robots;
        vector<int> answer;

        stack<ppc> st;

        for (int i = 0; i < n; i++) {
            ppc p = {positions[i], {healths[i], directions[i]}};
            robots.push_back(p);
        }

        sort(robots.begin(), robots.end());

        for (auto& el : robots) {
            int pos = el.first;
            int health = el.second.first;
            char dir = el.second.second;
            

            while(st.empty() && )

        }

        // continue code

        return answer;
    }
};

int main() {
    vector<int> positions = {5, 4, 3, 2, 1};
    vector<int> healths = {2, 17, 9, 15, 10};
    string directions = "RRRRR";

    Solution sol;
    vector<int> ans = sol.survivedRobotsHealths(positions, healths, directions);

    for (auto& x : ans) {
        cout << "x --> " << x << endl;
    }
}