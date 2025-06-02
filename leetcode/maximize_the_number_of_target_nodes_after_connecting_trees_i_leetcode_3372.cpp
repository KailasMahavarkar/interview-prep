#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using BFS)
// T.C : O(V*(V+E))
// S.C : O(V+E)
class Solution {
   public:
    // find max target nodes  (used for 2nd tree)
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k);
        vector<int> result2 = findCount(edges2, k - 1);

        int maxTargetNodesCount = *max_element(result2.begin(), result2.end());

        for (int i = 0; i < N; i++) {
            result1[i] += maxTargetNodesCount;
        }
        return result1;
    }

    int bfs(unordered_map<int, vector<int>>& adj, int curr, int d, int N) {
        queue<pair<int, int>> que;
        que.push({curr, 0});
        vector<bool> visited(N, false);
        visited[curr] = true;

        int count = 0;
        while (!que.empty()) {
            int currNode = que.front().first;
            int dist = que.front().second;
            que.pop();

            if (dist > d) {
                continue;
            }

            count++;

            for (auto& x : adj[currNode]) {
                if (!visited[x]) {
                    visited[x] = true;
                    que.push({x, dist + 1});
                }
            }
        }

        return count;
    }

    // find count for that tree (used for 1st tree)
    vector<int> findCount(vector<vector<int>>& edges, int d) {
        unordered_map<int, vector<int>> adj;
        int N = edges.size() + 1;
        vector<int> result(N);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < N; i++) {
            result[i] = bfs(adj, i, d, N);
        }

        return result;
    }
};

int main() {
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
    int k = 2;

    Solution sol;
    vector<int> ans = sol.maxTargetNodes(edges1, edges2, k);

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}