//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

    // Function to return Breadth First Traversal of given graph.
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends