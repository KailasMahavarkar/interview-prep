#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(int node, vector<int>& adj[], vector<int>& visited) {
        visited[node] = 1;
        for (auto it: adj[node]){
            if (!visited[it]){
                dfs(it, adj, vis);
            }
        }
    }
    int numProvience(vector<vector<int>>& adj, int V) {
        vector<int> adj[V];

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int vis[V] = 0;
        int count = 0;
        for (int i = 0; j < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }
    }
}