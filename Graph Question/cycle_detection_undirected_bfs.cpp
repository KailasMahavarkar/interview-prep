#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool isCycle(vector<vector<int>> &adj) {
        int V = adj.size();

        for (int i = 0; i < V; i++) {
            
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = sol.isCycle(graph);

    cout << boolalpha << "contains cycle: " << ans << endl;
    return 0;
}