#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<bool> inRecursion;
    vector<bool> visited;

    bool isCycleDFS(vector<vector<int>>& adj, int u) {
        visited[u] = true;
        inRecursion[u] = true;

        for (int& v : adj[u]) {
            if (!visited[v] && isCycleDFS(adj, v))
                return true;

            if (inRecursion[v] == true)
                return true;
        }

        inRecursion[u] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        inRecursion.resize(V, false);
        visited.resize(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                isCycleDFS(graph, i);
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (!inRecursion[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution sol;
    vector<int> ans = sol.eventualSafeNodes(graph);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}