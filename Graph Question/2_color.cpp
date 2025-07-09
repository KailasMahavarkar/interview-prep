#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<string>& color) {
        color[curr] = "red";
        queue<int> que;
        que.push(curr);

        while (!que.empty()) {
            int parent = que.front();
            que.pop();

            for (int& neighbour : adj[parent]) {
                if (color[neighbour] == color[parent]) {
                    return false;
                }

                if (color[neighbour] == "none") {
                    color[neighbour] = (color[parent] == "red") ? "blue" : "red";
                    que.push(neighbour);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {  // Fixed: removed unnecessary parameter
        int V = adj.size();
        vector<string> color(V, "none");

        for (int i = 0; i < V; i++) {
            if (color[i] == "none") {  // Fixed: check unvisited nodes
                if (!checkBipartiteBFS(adj, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {
        {1},
        {2, 4},
        {3, 1},
        {2, 4},
        {1, 3}};

    Solution sol;
    bool ans = sol.isBipartite(graph);  // Fixed: removed parameter
    cout << boolalpha << "ans --> " << ans << endl;
    return 0;
}