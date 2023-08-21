#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(int curr, unordered_map<int, vector<int>> &adj, vector<int> &visited, vector<int> &result) {
        if (visited[curr]) {
            return;
        }

        visited[curr] = true;
        result.push_back(curr);

        for (int &v : adj[curr]) {
            if (!visited[v]) {
                dfs(v, adj, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int, vector<int>> adj;

        for (int u = 0; u < V; u++) {
            for (auto v = mp[u].begin(); v != mp[u].end(); v++) {
                adj[u].push_back(*v);
            }
        }

        vector<int> result;
        vector<int> visited(V, false);

        dfs(0, adj, visited, result);

        return result;
    }
};

int main() {
    vector<vector<int>> vec = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    
    // create a adjacency list
    vector<int> adj[5];
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            adj[i].push_back(vec[i][j]);
        }
    }

    Solution sol;
    vector<int> ans = sol.dfsOfGraph(5, adj);

    for (auto &x : ans) {
        cout << x << " ";
    }
}