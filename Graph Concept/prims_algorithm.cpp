#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

class Solution {
   public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // weight (heap on basis of this)
        priority_queue<P, vector<P>, greater<P>> pq;  // {wt, node}
        vector<bool> visited(V, false);
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // check if node is visited
            if (visited[node]) {
                continue;
            }

            visited[node] = true;
            sum += wt;

            for (auto &x : adj[node]) {
                int neighbour = x[0];
                int neighbour_wt = x[1];

                if (!visited[neighbour]) {
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> adj[5];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});

    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});

    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});

    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[3].push_back({4, 9});

    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});
    adj[4].push_back({3, 9});

    cout << sol.spanningTree(5, adj) << endl;

    return 0;
}