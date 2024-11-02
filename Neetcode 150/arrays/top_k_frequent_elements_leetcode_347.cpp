#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/top-k-frequent-elements/description/
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> fmap;
        for (auto& x : nums) {
            fmap[x]++;
        }

        for (auto& x : fmap) {
            pq.push({x.second, x.first});
            while (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> answer;
        while (!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
