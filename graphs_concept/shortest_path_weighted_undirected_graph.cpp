#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            // (u) is connected with (v) with weight (w)
            // (v) is connected with (u) with weight (w)
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // pq<distance, node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n + 1, INT_MAX);
        vector<int> parent(n + 1);

        // in start everyone is their parent only
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // result[source] = 0 (meaning source agar 1 hai then 1 se 1 ki doori 0 hogi)
        result[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                // shape of single item in adj[node] is {node, weight}
                int adjNode = it.first;
                int dist = it.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        vector<int> path;
        int destNode = n;
        if (result[destNode] == INT_MAX) {
            return {-1};
        }

        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);

        reverse(begin(path), end(path));
        return path;
    }
};

int main() {
    int n = 5;
    int m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    Solution sol;
    sol.shortestPath(n, m, edges);
}