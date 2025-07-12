#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

typedef pair<int, int> pi;

class Graph {
   public:
    unordered_map<int, vector<pi>> adj;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    int shortestPath(int node1, int node2) {
        vector<int> result(N, INT_MAX);
        pq.push({0, node1});  // {wt, node}
        result[node1] = 0;

        while (!pq.empty()) {
            auto temp = pq.top();
            int weight = temp.first;
            int node = temp.second;
            pq.pop();

            for (auto child : adj[node]) {
                int currNode = child.first;
                int currWeight = child.second;

                if (currWeight + weight < result[currNode]) {
                    result[currNode] = currWeight + weight;
                    pq.push({currWeight + weight, currNode});
                }
            }
        }

        return result[node2] == INT_MAX ? -1 : result[node2];
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    Graph graph(n, edges);

    int node1 = 0;
    int node2 = 2;

    int result = graph.shortestPath(node1, node2);

    if (result != -1) {
        cout << "Shortest path from " << node1 << " to " << node2 << ": " << result << endl;
    } else {
        cout << "No path from " << node1 << " to " << node2 << " exists." << endl;
    }

    return 0;
}