#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    stack<int> st;
    vector<bool> visited;
    void DFS(int curr, unordered_map<int, vector<int>> &adj) {
        visited[curr] = true;

        for (auto &x : adj[curr]) {
            if (!visited[x]) {
                DFS(x, adj);
            }
        }

        // push all childs first -> DFS gurantees this
        // then push parent
        st.push(curr);
    }
    vector<int> topoSort(int V, unordered_map<int, vector<int>> &adj) {
        visited.resize(V, false);
        vector<int> result;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, adj);
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    unordered_map<int, vector<int>> adj;

    int V = arr.size();

    for (int i = 0; i < V; i++) {
        for (int &x : arr[i]) {
            adj[i].push_back(x);
        }
    }

    vector<int> answer = sol.topoSort(V, adj);

    cout << "Topological Sorting Order: ";
    for (int &node : answer) {
        cout << node << " ";
    }
}