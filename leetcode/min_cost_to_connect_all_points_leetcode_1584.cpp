#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

class Solution {
   public:
    int minMST(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> visited(n, false);
        pq.push({0, 0});  // {wt, node}
        int sum = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node]) {
                continue;
            }

            // mark visited
            visited[node] = true;
            sum += wt;

            for (auto& x : adj[node]) {
                int neighbour = x[0];
                int neighbour_wt = x[1];

                if (!visited[neighbour]) {
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>> adj;

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                auto pointA = points[i];
                int x1 = pointA[0];
                int y1 = pointA[1];

                auto pointB = points[j];
                int x2 = pointB[0];
                int y2 = pointB[1];

                int d = abs(x2 - x1) + abs(y2 - y1);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        return minMST(adj, V);
    }
};

int main() {
    Solution sol;
    int minCost = sol.minCostConnectPoints(points);
    cout << "min cost: " << minCost << endl;
}