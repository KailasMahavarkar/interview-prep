#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<bool> visited;
    stack<int> st;
    void DFS(int u, vector<int> adj[]) {
        visited[u] = true;

        // push all children into stack
        for (int &v : adj[u]) {
            if (!visited[v]) {
                DFS(v, adj);
            }
        }

        // push parent into stack
        // you have to think in terms of recursion
        // during recursion child nodes enter ho chuka h single parent ke liye
        // next time parent ko bhi enter karwana padega stack me
        st.push(u);
    }
    vector<int> topoSort(int V, vector<int> adj[]) {
        visited.resize(V, false);
        vector<int> result;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(adj, i);
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

