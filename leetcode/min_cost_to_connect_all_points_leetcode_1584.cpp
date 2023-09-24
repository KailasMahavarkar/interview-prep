#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

// Approach 1: Prims Algorithm
class Solution {
   public:
    int minMST(vector<vector<P>>& adj, int V) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> visited(V, false);
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
                int neighbour = x.first;
                int neighbour_wt = x.second;

                if (!visited[neighbour]) {
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                auto pointA = points[i];
                int x1 = pointA[0];
                int y1 = pointA[1];

                auto pointB = points[j];
                int x2 = pointB[0];
                int y2 = pointB[1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        return minMST(adj, V);
    }
};

// Approach 2: Kruskal Way
class SolutionKruskal {
   public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int xNode = find(x);
        int yNode = find(y);

        // both are already connected -> skip
        if (xNode == yNode) {
            return;
        }

        if (rank[xNode] > rank[yNode]) {
            parent[yNode] = xNode;
        } else if (rank[xNode] < rank[yNode]) {
            parent[xNode] = yNode;
        } else {
            parent[xNode] = yNode;
            rank[yNode]++;
        }
    }

    int kruskal(vector<vector<int>>& adj) {
        int sum = 0;
        for (auto& x : adj) {
            int u = x[0];
            int v = x[1];
            int d = x[2];

            int uParent = find(u);
            int vParent = find(v);

            if (uParent != vParent) {
                unionSet(u, v);
                sum += d;
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> adj;
        int V = points.size();
        parent.resize(V);
        rank.resize(V, 0);

        // initally everyone is their own parent
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                auto pointA = points[i];
                int x1 = pointA[0];
                int y1 = pointA[1];

                auto pointB = points[j];
                int x2 = pointB[0];
                int y2 = pointB[1];

                int d = abs(x2 - x1) + abs(y2 - y1);

                adj.push_back({i, j, d});
            }
        }

        // sort on basis of weight
        sort(adj.begin(), adj.end(), [&](auto& x, auto& y) {
            return x[2] < y[2];
        });

        return kruskal(adj);
    }
};

int main() {
    SolutionKruskal sol;
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int minCost = sol.minCostConnectPoints(points);
    cout << "min cost: " << minCost << endl;
}