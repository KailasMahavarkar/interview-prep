#include <bits/stdc++.h>
using namespace std;

// Method 1: Cycle Detection in directed graph
class SolutionOne {
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

// Method 2: Kahn's Algorithm (topological sort)
class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indegree(V, 0);
        queue<int> que;
        vector<int> result;

        unordered_map<int, vector<int>> adj;

        for (int u = 0; u < V; u++) {
            for (auto& v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int curr = que.front();
            result.push_back(curr);
            que.pop();

            for (auto& v : adj[curr]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return result;
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