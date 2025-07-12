#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<bool> visited;
    stack<int> st;
    void topoSortDFS(int u, vector<vector<int>>& adj) {
        // if already visited return
        if (visited[u]) {
            return;
        }

        // mark visited
        visited[u] = true;

        for (int& v : adj[u]) {
            if (!visited[v]) {
                topoSortDFS(v, adj);
            }
        }

        st.push(u);
    }

    void topoSort(int V, vector<vector<int>>& adj) {
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[i]) {
                topoSortDFS(i, adj);
            }
        }
    }

    void DFSkosaraju(int node, vector<vector<int>>& adjReversed) {
        if (visited[node]) {
            return;
        }

        // mark visited
        visited[node] = true;

        for (auto& x : adjReversed[node]) {
            if (!visited[x]) {
                DFSkosaraju(x, adjReversed);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& adj) {
        // make a reverse graph
        vector<vector<int>> adjReversed(V);
        visited.resize(V, false);

        // fill reverse of grpah (switch u->v with v->u)
        for (int u = 0; u < V; u++) {
            for (auto& v : adj[u]) {
                adjReversed[v].push_back(u);
            }
        }

        // get topological sorted order in stack;
        topoSort(V, adj);

        // run dfs on graph once more to get SCC count
        int countSCC = 0;
        visited = vector<bool>(V, false);
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                DFSkosaraju(node, adjReversed);
                countSCC++;
            }
        }

        return countSCC;
    }
};

int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
    vector<vector<int>> adj(V);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    // vector<int> ans = sol.topoSort(V, edges);
    // cout << "Topological Sorting Order: ";
    // for (int& node : ans) {
    //     cout << node << " ";
    // }

    int sccCount = sol.kosaraju(V, adj);
    cout << "No of strongly connected components: " << sccCount << endl;
    return 0;
}
