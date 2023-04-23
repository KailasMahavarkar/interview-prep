#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void bfs(
        int curr, vector<int> adj[],
        vector<bool> &visited, vector<int> &result) {
        queue<int> que;
        que.push(curr);
        result.push_back(curr);
        visited[curr] = true;

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u]) {
                if (!visited[v]) {
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }

    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, 0);
        vector<int> result;

        bfs(0, adj, visited, result);

        return result;
    }
};
