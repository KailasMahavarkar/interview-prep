#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();

        // build heap
        for (int i = n - 1; i >= 0; i--) {
            pq.push(stones[i]);
        }

        while (pq.size() >= 2) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            int smash = abs(second - first);
            pq.push(smash);
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    vector<int> stones = {7, 6, 7, 6, 9};
    Solution sol;
    int ans = sol.lastStoneWeight(stones);
    cout << "ans -->" << ans;
}