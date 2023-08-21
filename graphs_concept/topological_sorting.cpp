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
        // we are pushing parent after all children since stack reverses the order when we pop it
        st.push(u);
    }
    vector<int> topoSort(int V, vector<int> adj[]) {
        visited.resize(V, false);
        vector<int> result;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, adj);
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
    int V = 6;
    vector<int> adj[V] = {{1, 2}, {2, 3}, {4}, {4, 5}, {}, {}};

    Solution sol;
    vector<int> result = sol.topoSort(V, adj);

    cout << "Topological Sorting Order: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
