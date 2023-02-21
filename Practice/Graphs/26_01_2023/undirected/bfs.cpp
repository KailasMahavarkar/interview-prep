#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Solution {
   public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> que;

        // push inital node to queue
        que.push(0);
        visited[0] = true;
        result.push_back(0);

        while (!que.empty()) {
            int parent = que.front();
            que.pop();

            for (auto x : adj[parent]) {
                if (!visited[x]) {
                    que.push(x);
                    visited[x] = true;
                    result.push_back(x);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> adj[] = {{1, 2, 3}, {0}, {0, 4}, {0}, {2}};

    Solution sol;
    vector<int> result = sol.bfsOfGraph(5, adj);

    // expected: 0 1 2 3 4
    // current: 0 1 2 3 4
    printVector(result);
}