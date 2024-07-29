#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class SolutionFloyddWarshal {
   public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(101, vector<int>(101, 1000000));

        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }

        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];

            matrix[from][to] = weight;
            matrix[to][from] = weight;
        }

        // using floydd warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int globalMinValue = INT_MAX;
        int minimumIndex = -1;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && matrix[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= globalMinValue) {
                globalMinValue = count;
                minimumIndex = i;
            }
        }

        return minimumIndex;
    }
};

class SolutiondDijkstras {
   public:
    vector<int> shortestPath(int n, int source, vector<vector<pii>>& graph) {
        vector<int> distance(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, source});
        distance[source] = 0;

        while (!pq.empty()) {
            int curr_distance = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            if (curr_distance > distance[curr_node]) continue;

            for (const pii& neighbor : graph[curr_node]) {
                int v = neighbor.first;
                int wt = neighbor.second;

                if (distance[curr_node] + wt < distance[v]) {
                    distance[v] = distance[curr_node] + wt;
                    pq.push({distance[v], v});
                }
            }
        }

        return distance;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pii>> graph(n);

        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        int minReachableCities = n;
        int cityWithMinReachableCities = -1;

        for (int i = 0; i < n; ++i) {
            vector<int> dist = shortestPath(n, i, graph);
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                cityWithMinReachableCities = i;
            }
        }

        return cityWithMinReachableCities;
    }
};

class SolutionBellmanFord {
   public:
    vector<int> bellmanFordShortestPath(int n, int source, const vector<vector<int>>& edges) {
        vector<int> distance(n, INT_MAX);
        distance[source] = 0;

        // relax V-1 times
        for (int i = 0; i < n - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
                    distance[v] = distance[u] + wt;
                }

                if (distance[v] != INT_MAX && distance[v] + wt < distance[u]) {
                    distance[u] = distance[v] + wt;
                }
            }
        }

        return distance;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int minIndex = -1;
        int minValue = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> distance = bellmanFordShortestPath(n, i, edges);
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (distance[j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= minValue) {
                minValue = count;
                minIndex = i;
            }
        }
        return minValue;
    }
};

class Solution {
   public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        SolutionBellmanFord sol;
        return sol.findTheCity(n, edges, distanceThreshold);
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}};
    int distanceThreshold = 4;

    Solution sol;
    int ans = sol.findTheCity(n, edges, distanceThreshold);
    cout << "ans --> " << ans << endl;
}