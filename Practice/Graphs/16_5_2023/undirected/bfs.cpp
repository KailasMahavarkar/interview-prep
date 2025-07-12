#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<int> visited(V, false);
        queue<int> que;

        que.push(0);
        visited[0] = true;
        result.push_back(0);

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            for (int child : adj[curr]) {
                if (!visited[child]) {
                    que.push(child);
                    visited[child] = true;
                    result.push_back(child);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr[] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = sol.bfsOfGraph(4, arr);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}