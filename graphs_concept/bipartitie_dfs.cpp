#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkBipartiteDFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor) {
        color[curr] = currColor;  // color kardiya curr node ko

        // ab jaate hain adjacent nodes par
        for (int& v : adj[curr]) {
            if (color[v] == color[curr]) {
                return false;
            }

            if (color[v] == -1) {  // never colored (never visited)
                int colorOfV = 1 - currColor;
                if (checkBipartiteDFS(adj, v, color, colorOfV) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);  // no node colored in the start

        // red = 1
        // gree = 0

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (checkBipartiteDFS(adj, i, color, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    Solution sol;
    bool ans = sol.isBipartite(graph);
    cout << boolalpha << "ans: " << ans << endl;
}