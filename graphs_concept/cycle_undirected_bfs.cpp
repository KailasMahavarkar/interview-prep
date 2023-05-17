#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isCycleBFS(int start, int parent, vector<int> adj[], vector<bool> &visited) {
        queue<pair<int, int>> que;
        que.push({start, -1});
        visited[start] = true;

        while (!que.empty()) {
            pair<int, int> k = que.front();
            que.pop();

            int curr = k.first;
            int parent = k.second;

            for (int child : adj[curr]) {
                // dont visit node where you came from
                if (child == parent) continue;

                // if child is already visited we have cycle
                if (visited[child]) {
                    return true;
                } else {
                    que.push({child, curr});
                    visited[child] = true;
                }
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
                if (isCycleBFS(i, -1, adj, visited)) {
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