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

    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, vector<int> &indegree) {
        queue<int> que;
        int count = 0;
        vector<int> result;

        // 1. push lowest indegree into queue
        for (int u = 0; u < n; u++) {
            if (indegree[u] == 0) {
                que.push(u);
                result.push_back(u);
                count++;
            }
        }

        // 2. bfs until queue is not empty
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    count++;
                    que.push(v);
                    result.push_back(v);
                }
            }
        }

        if (n == count) {  // i was able to visit all courses
            return result;
        }

        // unable to visit all courses
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        n = numCourses;
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

        return topologicalSort(adj, indegree);
    }
};