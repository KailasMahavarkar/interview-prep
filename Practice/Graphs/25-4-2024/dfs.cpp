#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<bool> visited;
    vector<int> result;
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        visited.resize(V, false);
        result.resize(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                solve(V, adj);
            }
        }

        return result;
    }
};

int main() {
    vector<int> adj[] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    Solution sol;
    vector<int> ans = sol.dfsOfGraph(5, adj);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
