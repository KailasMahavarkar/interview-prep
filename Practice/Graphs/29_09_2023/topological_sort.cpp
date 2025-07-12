#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    stack<int> st;
    vector<int> visited;
    void DFS(int u, vector<int> adj[]) {
        visited[u] = true;

        for (auto &v : adj[u]) {
            if (!visited[v]) {
                DFS(v, adj);
            }
        };

        // push all children in stack
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
    Solution sol;
    int V = 5;
    vector<int> arr[V] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    vector<int> ans = sol.topoSort(V, arr);

    cout << "Topological Sorting Order: ";
    for (int &node : ans) {
        cout << node << " ";
    }

    return 0;
}
