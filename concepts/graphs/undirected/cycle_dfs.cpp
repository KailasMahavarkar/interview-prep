#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<bool> visited;
    bool isCycleDFS(vector<int> adj[], int current, int parent) {
        // mark node visited
        visited[current] = true;

        // from that current node visit next neighbour if its not visited
        for (int &v : adj[current]) {
            // skip parent position since we came from that point
            // if we go back it will be considered as cycle even though its not
            if (v == parent) {
                continue;
            }

            if (visited[v]) {
                // we found cycle since node is visited twice
                return true;
            }

            if (isCycleDFS(adj, v, current)) {
                return true;
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
                if (isCycleDFS(adj, i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
