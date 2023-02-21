#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long fuel = 0;
    int dfs(int curr, int parent, unordered_map<int, vector<int>>& adj, int seats) {
        int count = 0;

        for (auto& child : adj[curr]) {
            if (child != parent) {
                int subcount = dfs(child, curr, adj, seats);
                count += subcount;
                fuel += ceil(subcount * (1.0) / seats);
            }
        }

        return count + 1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> adj;

        for (auto& x : roads) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
};

int main() {
    vector<vector<int>> roads ={{0, 1}, {1, 2}, {2, 3}, {2, 4}, {4, 5}};
    Solution sol;
    long long ans = sol.minimumFuelCost(roads, 2);
    cout << "ans -->" << ans;
}