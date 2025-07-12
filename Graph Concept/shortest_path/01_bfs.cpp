#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<int> BFS01(int V, vector<vector<int>> adj[], int S) {
        deque<int> dq;
        vector<int> distance(V, INT_MAX);

        distance[S] = 0;
        dq.push_front(S);

        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();

            for (auto &x : adj[node]) {
                int neighbour = x[0];
                int wt = x[1];

                int new_dist = distance[node] + wt;

                if (new_dist < distance[neighbour]) {
                    distance[neighbour] = new_dist;

                    if (wt == 0) {
                        dq.push_front(neighbour);
                    } else {
                        dq.push_back(neighbour);
                    }
                }
            }
        }

        return distance;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> adj[] = {
        {{1, 1}, {4, 0}},
        {{2, 1}, {5, 0}},
        {{3, 1}},
        {},
        {{5, 0}, {6, 1}},
        {{6, 0}},
        {{3, 0}}};

    // Direct Path (expensive):
    // 0 ---[1]--> 1 ---[1]--> 2 ---[1]--> 3
    // |                                   |
    // 0 ---[0]--> 4 ---[0]--> 5 ---[0]--> 6 ---[0]--> 3
    vector<int> ans = sol.BFS01(7, adj, 0);

    cout << "Shortest path from source to all nodes: ";
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}