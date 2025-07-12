#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int n;

    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;

        // 1. push lowest indegree into queue
        for (int u = 0; u < n; u++) {
            if (indegree[u] == 0) {
                que.push(u);
            }
        }

        // 2. bfs until queue is not empty
        int count = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
            }
        }

        if (n == count){ // i was able to visit all courses
            return true;
        }

        // unable to visit all courses
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        // 1. find indegree of nodes
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // b --> a
            adj[b].push_back(a);

            // arrow a me jaa rha h
            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 0}, {0, 1}};
    Solution sol;
    int ans = sol.canFinish(matrix);
    cout << "ans  -->" << ans << endl;
}
