#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);

        result[S] = 0;
        pq.push({0, S});  // souce se source tak pohoch ne me 0 lag rha h

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &x : adj[node]) {
                int subnode = x[0];
                int curr_cost = x[1];

                if (cost + curr_cost < result[subnode]) {
                    result[subnode] = cost + curr_cost;
                    pq.push({cost + curr_cost, subnode});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> adj[] = {{{1, 1}, {2, 4}}, {{2, 2}, {3, 6}}, {{3, 3}}, {}};
    vector<int> ans = sol.dijkstra(4, adj, 0);

    cout << "Shortest path from source to all nodes: ";
    for (int &node : ans) {
        cout << node << " ";
    }

    return 0;
}