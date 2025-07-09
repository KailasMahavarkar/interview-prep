#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<string>& color, string c) {
        color[curr] = c;

        for (auto neighbour : adj[curr]) {
            if (color[neighbour] == c) {
                return false;
            }

            if (color[neighbour] == "none") {
                string selectedColor = (c == "red" ? "blue" : "red");
                if (!checkBipartiteBFS(adj, neighbour, color, selectedColor)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<string> color(V, "none");

        for (int i = 0; i < V; i++) {
            if (!checkBipartiteBFS(adj, i, color, "red")) {
                return false;
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
    bool ans = sol.isBipartite(graph);
    cout << boolalpha << "ans --> " << ans << endl;
    return 0;
}