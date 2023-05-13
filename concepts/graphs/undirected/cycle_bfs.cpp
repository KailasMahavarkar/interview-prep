#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<bool> visited;
    bool isCycleBFS(vector<int> adj[], int start) {
        queue<pair<int, int>> que;

        // push start node and its parent
        que.push({start, -1});
        visited[start] = true;

        while (!que.empty()) {
            pair<int, int> node = que.front();
            que.pop();

            int current = node.first;
            int parent = node.second;

            for (int &v : adj[current]) {
                if (!visited[v]) {
                    que.push({v, current});
                    visited[v] = true;
                } else if (v != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        visited.resize(V, false);

        // we are assuming graphs are component bases thus this loop is required
        for (int i = 0; i < V; i++) {
            // when node is not visited
            if (!visited[i]) {
                if (isCycleBFS(adj, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};
