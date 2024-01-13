#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<bool> visited;
    stack<int> st;

    void topologicalSort(int u, vector<vector<pair<int, int>>>& graph) {
        visited[u] = true;
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            if (!visited[v]) {
                topologicalSort(v, graph);
            }
        }
        st.push(u);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Step 1: Build the graph
        vector<vector<pair<int, int>>> graph(N);  // (neighbor, weight)
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
        }

        // Step 2: Topological Sort
        visited.assign(N, false);
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                topologicalSort(i, graph);
            }
        }

        // Step 3: Initialize shortest distances
        vector<int> distance(N, INT_MAX);
        distance[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (distance[u] != INT_MAX) {
                for (const auto& neighbor : graph[u]) {
                    int v = neighbor.first;
                    int w = neighbor.second;
                    if (distance[u] + w < distance[v]) {
                        distance[v] = distance[u] + w;
                    }
                }
            } else {
                distance[u] = -1;
            }
        }

        return distance;
    }
};

int main() {
    Solution sol;
    int N = 4, M = 2;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<int> ans = sol.shortestPath(N, M, edges);

    for (int& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}