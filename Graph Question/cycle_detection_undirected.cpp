#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool hasCycle(vector<vector<int>>& adj, vector<bool>& visited, int curr, int parent) {
        visited[curr] = true;

        for (auto neighbour : adj[curr]) {
            if (parent == neighbour) continue;

            if (visited[neighbour]) {
                return true;
            }

            if (hasCycle(adj, visited, neighbour, curr)) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (hasCycle(adj, visited, i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = sol.isCycle(graph);

    cout << boolalpha << "contains cycle: " << ans << endl;
    return 0;
}