#include <bits/stdc++.h>
using namespace std;

// cycle can only be possible if 
// 1) current is in inRecursion
// 2) we get true as answer from child dfs calls 

class Solution {
   public:
    vector<bool> visited;
    vector<bool> inRecursion;
    bool isCycleDFS(int curr, vector<int> adj[]) {
        // mark visited
        visited[curr] = true;
        inRecursion[curr] = true;

        for (int &child : adj[curr]) {
            // if not visited then we check for cycle in DFS
            if (visited[child] == false) {
                if (isCycleDFS(child, adj)) {
                    return true;
                }
            }

            // visited and it is in current recursion
            if (inRecursion[child]) {
                return true;
            }
        }

        inRecursion[curr] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        visited.resize(V, false);
        inRecursion.resize(V, false);

        // we are assuming graphs are component based
        for (int i = 0; i < V; i++) {
            // when node is not visited
            if (!visited[i]) {
                if (isCycleDFS(i, adj)) {
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