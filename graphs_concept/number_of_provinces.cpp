#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int n;
    void dfs(vector<vector<int>>& isConnected, int curr, vector<bool>& visited) {
        if (visited[curr]) return;

        visited[curr] = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && isConnected[curr][i] == 1) {
                dfs(isConnected, i, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                result++;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> connections = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution obj;
    cout << obj.findCircleNum(connections) << endl;
    return 0;
}