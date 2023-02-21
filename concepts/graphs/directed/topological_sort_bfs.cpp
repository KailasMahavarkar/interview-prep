#include <bits/stdc++.h>
using namespace std;

// Kahn algorithm is also called topological sort using BFS
class Solution {
   public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        queue<int> que;

        // store indegree of nodes;
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                indegree[v]++;
            }
        }

        // Fill Que, with nodes having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }


        vector<int> result;
        while (!que.empty()) {
            int u = que.front();
            result.push_back(u);
            que.pop();

            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        return result;
    }
};

int main() {
}