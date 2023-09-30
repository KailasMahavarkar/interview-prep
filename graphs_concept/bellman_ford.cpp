#include <bits/stdc++.h>
using namespace std;

// Why do we use bellman_ford?
// >> shortest path from source to all vertices in a graph

class Solution {
   public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> result(V, 1e8);
        result[S] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (result[u] != 1e8 && result[u] + wt < result[v]) {
                    result[v] = result[u] + wt;
                }
            }
        }

        // now detect -ve cycle
        // relax 1 more time -> if it relaxes we are in -ve cycle
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (result[u] != 1e8 && result[u] + wt < result[v]) {
                return {-1};
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};
    Solution sol;
    vector<int> ans = sol.bellman_ford(3, edges, 2);
    cout << "ans --> " << ans << endl;
}