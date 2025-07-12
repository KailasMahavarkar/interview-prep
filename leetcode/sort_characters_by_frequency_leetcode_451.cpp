#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/sort-characters-by-frequency/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    vector<int> freq(26, 1);
    string frequencySort(string s) {
        for (auto &x : s) {
            freq[x - 'a']++;
        }
        priority_queue<pair<int, int>> pq;
        return "";
    }
};

int main() {
    Solution sol;
    string s = "bbbbcccaa";
    string answer = sol.frequencySort(s);

    cout << "answer --> " << answer << endl;
}
