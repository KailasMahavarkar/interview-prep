#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Method 1: using DFS
class SolutionOne {
   public:
    int n = 0;
    void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                DFS(v, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                DFS(i, isConnected, visited);
            }
        }

        return count;
    }
};

// Method 2: using BFS
class Solution {
   public:
    int n;
    void BFS(int u, vector<vector<int>> &adj, vector<bool> &visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            for (int v = 0; v < n; v++) {
                if (adj[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                BFS(i, isConnected, visited);
            }
        }

        return count;
    }
};

int main() {
    vector<vector<int>> connections = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};
    Solution obj;
    cout << obj.findCircleNum(connections) << endl;
    return 0;
}