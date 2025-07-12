#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool isCycle(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> indegree(V, 0);
        queue<int> que;
        int count = 0;

        for (auto &list : adj) {
            for (auto &v : list) {
                indegree[v]++;
            }
        }

        for (auto &i: indegree) {
            if (i == 0){
                que.push(i);
                count++;
            }
        }

        while(!que.empty()){
            int parent = que.front();
            que.pop();

            for(auto &x: adj[parent]){
                indegree[x]--;

                if (indegree[x] == 0){
                    que.push(x);
                    count++;
                }
            }
        }

        if (count != V){
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = sol.isCycle(graph);

    cout << boolalpha << "contains cycle: " << ans << endl;
    return 0;
}