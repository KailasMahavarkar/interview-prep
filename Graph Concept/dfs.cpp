#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(int curr, vector<int> adj[], vector<bool> &visited, vector<int> &answer) {
        if (visited[curr]) return;
        visited[curr] = true;
        answer.push_back(curr);  

        for (int &v : adj[curr]) {
            if (!visited[v]) {
                dfs(v, adj, visited, answer);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> answer;

        // always assume graph is component based and not connected
        // this handles test cases for disconnected graphs
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, answer);
            }
        }
        return answer;
    }
};
