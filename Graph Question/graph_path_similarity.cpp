#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<vector<int>> graph;
    vector<string> names;
    vector<string> target;
    map<pair<int, int>, pair<int, vector<int>>> memo;

    pair<int, vector<int>> solve(int pos, int city) {
        // Base case
        if (pos == target.size()) {
            return {0, {}};
        }

        // Check memoization
        pair<int, int> key = {pos, city};
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Current position cost
        int cost = (names[city] == target[pos]) ? 0 : 1;

        int min_cost = INT_MAX;
        vector<int> best_path;

        // Try all neighbors
        for (int neighbor : graph[city]) {
            auto result = solve(pos + 1, neighbor);
            int total_cost = cost + result.first;

            if (total_cost < min_cost) {
                min_cost = total_cost;
                best_path = {city};
                best_path.insert(best_path.end(), result.second.begin(), result.second.end());
            }
        }

        // Memoize and return
        memo[key] = {min_cost, best_path};
        return {min_cost, best_path};
    }

   public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& city_names,
                            vector<string>& targetPath) {
        // Build graph
        graph.assign(n, vector<int>());
        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        names = city_names;
        target = targetPath;
        memo.clear();

        int overall_min = INT_MAX;
        vector<int> best_solution;

        // Try starting from each city
        for (int start = 0; start < n; start++) {
            auto result = solve(0, start);
            if (result.first < overall_min) {
                overall_min = result.first;
                best_solution = result.second;
            }
        }

        return best_solution;
    }
};

int main() {
    Solution sol;

    // Test case
    int n = 3;
    vector<vector<int>> roads = {{0, 1}, {1, 2}};
    vector<string> names = {"DEL", "CHE", "BLR"};
    vector<string> target = {"DEL", "BLR", "MUM"};

    vector<int> result = sol.mostSimilar(n, roads, names, target);

    // Print result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}