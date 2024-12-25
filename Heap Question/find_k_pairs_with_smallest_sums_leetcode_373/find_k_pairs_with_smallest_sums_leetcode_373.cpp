#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("03,unroll-loops")

// Approach-1 (Optimal Heap)
// TC : O(k log k)
// SC : O(k)
class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> result;

        // loop cost: O(log k) * k -> O(k log k)
        // push sum with incremented i to heap (keeping j as 0)
        for (int i = 0; i < nums1.size(); i++) {
            if (i < k) {
                int sum = nums1[i] + nums2[0];
                pq.push({sum, i, 0});
            }
        }

        // nums1: [1, 7, 11]
        // nums2: [2, 4, 6]
        // After this point heap will have
        // --> [(1+2, 0, 0), (7+2, 1, 0), (11+2, 2, 1)]
        // --> [(3, 0, 0), (9, 1, 0), (11, 2, 1)]

        // now we pick each element from heap and generate new element after this point
        // loop cost: O(log k) * k -> O(k log k)
        while (!pq.empty() && k > 0) {
            vector<int> top = pq.top();
            pq.pop();

            // whatever is at heap top is the lowest value
            result.push_back({nums1[top[1]], nums2[top[2]]});

            int i = top[1];
            int j = top[2];

            // re-validate index and generate new index on fly
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }

            k--;
        }

        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    Solution sol;
    vector<vector<int>> ans = sol.kSmallestPairs(nums1, nums2, k);

    for (auto& x : ans) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}
