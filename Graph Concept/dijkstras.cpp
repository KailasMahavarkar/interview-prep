#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);

        result[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            int weight = top.first;
            int node = top.second;
            pq.pop();

            for (auto &x : adj[node]) {
                int sub_node = x[0];
                int wt = x[1];

                if (weight + wt < result[sub_node]) {
                    result[sub_node] = weight + wt;
                    pq.push({wt + weight, sub_node});
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