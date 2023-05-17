#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(int curr, vector<int> adj[], vector<int> &visited, vector<int> &result) {
        if (visited[curr]) {
            return;
        }

        visited[curr] = true;
        result.push_back(curr);

        for (int &v : adj[curr]) {
            if (!visited[v]) {
                dfs(v, adj, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<int> visited(V, false);

        dfs(0, adj, visited, result);

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr[] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = sol.dfsOfGraph(4, arr);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}