#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<int> visited;
    vector<int> recursionStack;

    bool dfs(vector<vector<int>> &adj, int curr) {
        recursionStack[curr] = true;
        visited[curr] = true;

        for (auto &x : adj[curr]) {
            if (!visited[x]) {
                if (dfs(adj, x)) {
                    return true;
                }
            }

            if (recursionStack[x]) {
                return true;
            }
        }
        recursionStack[curr] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &arr) {
        visited.resize(V, false);
        recursionStack.resize(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(arr, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = sol.isCyclic(5, arr);
    cout << boolalpha << "contains cycle: " << ans << endl;
    return 0;
}
