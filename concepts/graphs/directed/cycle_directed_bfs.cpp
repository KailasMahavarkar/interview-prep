#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int nodeCount = 0;
    int n;
    bool isCyclic(int V, vector<int> adj[]) {
        n = V;
        vector<int> indegree(V, 0);
        queue<int> que;

        // 1. indegree
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                indegree[v]++;
            }
        }

        // 2. push the lowest indegree into queue
        for (int u = 0; u < V; u++) {
            if (indegree[u] == 0) {
                que.push(u);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            nodeCount++;
            que.pop();

            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        if (nodeCount == V){
            return false; // no cycle detected
        }else{
            return true; // cycle detected
        }
    }
};
