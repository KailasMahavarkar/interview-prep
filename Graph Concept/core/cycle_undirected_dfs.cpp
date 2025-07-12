#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool isCycleDFS(int curr, int parent, vector<int> adj[], vector<bool> &visited) {
        // mark visited
        visited[curr] = true;

        for (int child : adj[curr]) {
            // dont visit node where you came from
            if (child == parent) continue;

            // if child is already visited we have cycle
            if (visited[child]) {
                return true;
            }

            // if recursion contains cycle we have cycle
            if (isCycleDFS(child, curr, adj, visited)) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        // we are assuming graphs are component based
        for (int i = 0; i < V; i++) {
            // when node is not visited
            if (!visited[i]) {
                if (isCycleDFS(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = sol.isCycle(4, arr);

    cout << boolalpha << "contains cycle: " << ans << endl;
    return 0;
}