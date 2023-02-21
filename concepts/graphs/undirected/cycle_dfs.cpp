#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isCycleDFS(vector<int> adj[], int u, int parent, vector<bool> &visited){
        visited[u] = true;

        for (int &v: adj[u]){
            if (v == parent) continue;

            if (visited[v]){
                return true;
            }
            if (isCycleDFS(adj, v, u, visited)){
                return true;
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]){
        vector<bool> visited(V, 0);
        for (int i=0; i < V; i++){
            if (!visited[i] && isCycleDFS(adj, i, -1, visited)){
                return true;
            }
        }
        return false;
    }
};
