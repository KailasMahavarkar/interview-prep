#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, vector<pair<int, int>>> adj;

        vector<int> result(n, INT_MAX);

        // Step 1: build adj list
        for (auto& x : times) {
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // each item in pq is {weight, node}
        pq.push({0, k});
        result[k] = 0;

        while (!pq.empty()) {
            int total_weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // from curr node visit all its children
            for (auto& x : adj[node]) {
                int curr_node = x.first;
                int curr_weight = x.second;

                if (total_weight + curr_weight < result[curr_node]) {
                    pq.push({total_weight + curr_weight, curr_node});
                    result[curr_node] = total_weight + curr_weight;
                }
            }
        }

        // iterate though all result using STL
        int total = *max_element(result.begin(), result.end());
        return total == 0 ? -1 : total;
    }
};

int main() {
    Solution sol;
    sol.networkDelayTime();
}