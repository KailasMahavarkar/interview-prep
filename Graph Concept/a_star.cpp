#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    // assuming heuristics are optimal
    vector<int> minimunPathCost(int source, int destination, vector<int> &actual_cost, vector<int> &heuristics, unordered_map<int, vector<pair<int, int>>> &adjList) {
        int V = actual_cost.size();
        vector<int> result(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        actual_cost.resize(V, INT_MAX);
        actual_cost[source] = 0;
        pq.push({0 + heuristics[source], source});

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int choice_cost = p.first;
            int choice_node = p.second;

            if (choice_node == destination) {
                break;
            }

            if (choice_cost > actual_cost[choice_node] + heuristics[choice_node]) {
                continue;
            }

            // we visit all nodes connected to choice node
            for (auto &x : adjList[choice_node]) {
                int node = x.first;
                int cost = x.second;
                int new_actual_cost = actual_cost[choice_node] + cost;

                // the path where we came to this node is compared with what we have stored in actual_cost
                // in other words... for current node "node" we found a better path
                // A -> (B, C, D) ... this means to visit B we must have taken A + current_path cost(cost)
                // so the path we just explored is better than stored then it must be better (may/maynot be optimal)
                if (new_actual_cost < actual_cost[node]) {
                    actual_cost[node] = new_actual_cost;
                    result[node] = new_actual_cost;
                    pq.push({new_actual_cost + heuristics[node], node});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> actual_cost(4, INT_MAX);
    vector<int> heuristics = {8, 9, 3, 0};

    unordered_map<int, vector<pair<int, int>>> adjList = {
        {0, {{1, 2}, {2, 20}}},
        {1, {{3, 50}}},
        {2, {{3, 1}}}};

    vector<int> result = sol.minimunPathCost(0, 3, actual_cost, heuristics, adjList);

    cout << "Shortest path cost: " << result[3] << endl;
    return 0;
}