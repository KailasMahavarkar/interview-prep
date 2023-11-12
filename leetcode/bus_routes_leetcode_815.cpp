#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();

        // imagine each route as a cycle and multiple cycles may or may not be connected to each other
        // lets call these cycles as R1, R2, R3... Rn

        //     [1]            [4]
        //    /r1 \           /r2\
        //  [2]---[3] <---> [5]--[6]

        // connecting edges between two cycles is where you can change buses
        // we need information at which bus stop ... which route falls under
        // like stop [3] fall under both route1 and route2
        // like stop [6] fall just under route2
        // question: we start from source stop [x], we need minimum route count by which we can reach destination stop [y]

        unordered_map<int, vector<int>> adj;
        for (int route = 0; route < n; route++) {
            for (auto stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;
        vector<int> visited(n, false);

        // mark all initial routes (which could be multiple) as visited
        // meaning from stop[3] we could take route1 and route2 ... thus our minimum can come from either of them
        for (auto route : adj[source]) {
            que.push(route);
            visited[route] = true;
        }

        int busCount = 1;
        while (!que.empty()) {
            int levelSize = que.size();

            for (int i = 0; i < levelSize; i++) {
                int route = que.front();
                que.pop();

                // from current stop we can visit [r1, r2.... ] routes
                for (auto& stop : routes[route]) {
                    if (stop == target) {
                        return busCount;
                    }

                    for (auto nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1;
    int target = 6;

    int ans = sol.numBusesToDestination(routes, source, target);
    cout << "ans -->" << ans << endl;
}