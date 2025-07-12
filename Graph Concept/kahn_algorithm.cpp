#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Kahn's Algorithm
// Time Complexity: O(V+E)
// Space Complexity: O(V)

// What is Kahn's Algorithm?
// Its nothing but topological sorting using BFS

class Solution {
   public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> result;
        unordered_map<int, int> indegree;
        queue<int> que;

        // build indegree network
        for (int i = 0; i < V; i++) {
            for (int &child : adj[i]) {
                indegree[child]++;
            }
        }

        // fill queue, with nodes having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int curr = que.front();
            result.push_back(curr);
            que.pop();

            // visit all children of current and reduce its indegree
            // when indegree reaches 0 push it into queue
            for (int &v : adj[curr]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int V = 5;
    vector<int> arr[V] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    vector<int> ans = sol.topoSort(V, arr);

    cout << "Topological Sorting Order: ";
    for (int &node : ans) {
        cout << node << " ";
    }

    return 0;
}
