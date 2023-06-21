#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) return -1;
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {8, 9}};
    int n = 9;
    cout << sol.makeConnected(n, connections) << endl;

    return 0;
}