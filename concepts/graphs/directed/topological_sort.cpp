#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<int> adj[], int curr, vector<int> &visited, stack<int> &st) {
        visited[curr] = true;
        for (int &child : adj[curr]) {
            if (!visited[curr]) {
                dfs(adj, child, visited, st);
            }
        }
        st.push(curr);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited, st)
            }
        }

        vector<int> result;

        while (!st.empty()) {
            int temp = st.top();
            result.push_back(temp);
            st.pop();
        }

        return result;
    }
};
