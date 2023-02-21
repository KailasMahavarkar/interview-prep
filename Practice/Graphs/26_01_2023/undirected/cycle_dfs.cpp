//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfsHelper(vector<int> *adj, int curr, int parent, vector<bool> &visited) {
        visited[curr] = true;

        for (int &v : adj[curr]) {
            // note for inputs {1, 2, 3} if 1 is parent then we dont visit 1
            if (v == parent) {
                continue;
            }
            if (visited[curr]) {
                return true;
            } else {
                if (dfsHelper(adj, v, curr, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (dfsHelper(adj, i, -1, visited)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> task[] = {{1}, {0, 2, 3}, {1, 3}, {1, 2}};
    Solution sol;
    bool ans = sol.isCycle(4, task);
    cout << boolalpha << ans;
}