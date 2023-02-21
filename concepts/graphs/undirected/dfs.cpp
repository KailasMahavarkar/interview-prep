//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    void DFS(unordered_map<int, vector<int>>& adj, int curr, vector<bool>& visited, vector<int>& result){
        if (visited[curr] == true) return;
        visited[curr] = true;

        result.push_back(curr);
        for (int &v: adj[curr]){
            if (!visited[v]){
                DFS(adj, v, visited, result);
            }            
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int, vector<int>> adj;

        for (int u=0; u < V; u++){
            for (auto v=mp[u].begin(); v != mp[u].end(); v++){
                adj[u].push_back(*v);
            }
        }
        
        vector<int> result;
        vector<bool> visited(V, false);
        DFS(adj, 0, visited, result);
        return result;
    }
};

