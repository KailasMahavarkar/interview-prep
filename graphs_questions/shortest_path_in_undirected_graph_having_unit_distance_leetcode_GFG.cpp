#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        unordered_map<int, vector<int>> adj;
        vector<int> result(N, -1);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> curr = edges[i];
            adj[curr[0]].push_back(curr[1]);
            adj[curr[1]].push_back(curr[0]);
        }

        queue<pair<int, int>> que;  // {node, weight}
        que.push({src, 0});
        result[src] = 0;

        while (!que.empty()) {
            int node = que.front().first;
            int weight = que.front().second;
            que.pop();

            for (auto& v : adj[node]) {
                if (result[v] == -1) {  // meaning no path was found for this node
                    result[v] = weight + 1;
                    que.push({v, weight + 1});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int N = 9, M = 10, src = 0;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    vector<int> ans = sol.shortestPath(edges, N, M, src);

    cout << "Shortest Path: ";
    for (int& node : ans) {
        cout << node << " ";
    }
}