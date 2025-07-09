#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, int> indegree;
        int count = 0;
        queue<int> que;

        // build indegree network
        for (int i = 0; i < V; i++) {
            for (int &child : adj[i]) {
                indegree[child]++;
            }
        }

        // fill queue, with nodes having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            // visit all children of current and reduce its indegree
            // when indegree reaches 0 push it into queue
            for (int &v : adj[curr]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }

        if (count == V) {
            return false;  // cycle not detected
        }
        return true;  // cycle detected
    }
};

int main() {
    Solution sol;
    vector<int> arr[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool ans = sol.isCyclic(5, arr);
    cout << boolalpha << "contains cycle: " << ans << endl;
    return 0;
}
