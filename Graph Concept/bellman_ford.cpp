#include <iostream>
#include <vector>
#include <climits>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Why do we use bellman_ford?
// >> shortest path from source to all vertices in a graph

// Time Complexity: O(V * E)  <- connected graph
// Time Complexity: O(V² * E) <- disconnected graph
// Space Complexity: O(V)
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

                // lets say A->B is a edge we are checking for
                // here u -> A
                // here v -> B
                // we are checking if u(current source) + edge weight (wt) < v (we are about to go)
                // then we found much shorter path... so update v (node)
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

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}