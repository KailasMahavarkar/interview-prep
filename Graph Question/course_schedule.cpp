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
    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, vector<int> &indegree) {
        queue<int> que;
        int count = 0;

        // push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }

        // no cycle was detected (since count matches node n)
        if (count == n) {
            return true; // i was able to finish all courses
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);  // kahn's algorithm

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // b -> a
            adj[b].push_back(a);

            indegree[a]++;
        }

        // if cycle is present not possible
        return topologicalSortCheck(adj, indegree);
    }
};