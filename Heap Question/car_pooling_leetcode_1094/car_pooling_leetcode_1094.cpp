#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
typedef pair<int, int> pi;

/*
    Problem Link   : https://leetcode.com/problems/car-pooling/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Heap)
// TC : O(nlogn + n) -> O(nlogn)
// SC : O(1)
class SolutionBrute {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        sort(trips.begin(), trips.end(), [&](vector<int> a, vector<int> b) { return a[1] < b[1]; });
        int current_capacity = 0;

        for (auto& x : trips) {
            int p = x[0];
            int s = x[1];
            int e = x[2];

            while (!pq.empty() && pq.top().first <= s) {
                // remove previous trip from heap if it ended
                current_capacity -= pq.top().second;
                pq.pop();
            }

            pq.push({e, p});
            current_capacity += p;
            if (current_capacity > capacity) {
                return false;
            }
        }

        return true;
    };
};

// Approach-1 (Heap + Sweepline algorithm)
// TC : O(nlogn + n) -> O(nlogn)
// SC : O(1)
class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pi> events;

        for (auto& x : trips) {
            int p = x[0];
            int s = x[1];
            int e = x[2];

            events.push_back({s, p});
            events.push_back({e, -p});
        }

        sort(events.begin(), events.end());

        int currentCapacity = 0;
        for (auto& ev : events) {
            currentCapacity += ev.second;
            if (currentCapacity > capacity) {
                return false;
            }
        }

        return true;
    };
};

int main() {
    vector<vector<int>> vec = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 5;

    Solution sol;
    bool res = sol.carPooling(vec, capacity);
    cout << boolalpha << "result --> " << res << endl;
}