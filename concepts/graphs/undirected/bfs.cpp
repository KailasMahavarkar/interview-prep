#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void BFS(unordered_map<int, vector<int>>& adj, int curr, vector<bool>& visited, vector<int>& result){
        queue<int> que;
        que.push(curr);
        visited[curr] = true;
        result.push_back(curr);

        while (!que.empty()){
            int parent = que.front();
            que.pop();

            for (auto child: adj[parent]){
                if (!visited[child]){
                    que.push(child);
                    visited[child] = true;
                    result.push_back(child);
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int, vector<int>> adj;
        for (int curr=0; curr < V; curr++){
            for(auto child=mp[curr].begin(); child != mp[curr].end(); child++){
                adj[curr].push_back(*child);
            }
        }

        vector<int> result;
        vector<bool> visited(V, false);
        BFS(adj, 0, visited, result);
        return result;
    }
};


int main() {
    vector<vector<int>> vec = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    
    vector<int> adj[5];
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            adj[i].push_back(vec[i][j]);
        }
    }

    Solution sol;
    vector<int> ans = sol.bfsOfGraph(5, adj);

    for (auto &x : ans) {
        cout << x << " ";
    }
}