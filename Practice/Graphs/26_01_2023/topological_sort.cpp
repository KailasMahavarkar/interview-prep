#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st) {
        visited[u] = true;

        // this will push all childs of u to stack
        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited, st);
            }
        }

        // after pushing children we push parent
        // implying relation u -> v 
        st.push(u);
    }
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited, st);
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

int main() {
}