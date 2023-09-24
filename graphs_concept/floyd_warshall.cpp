#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void shortest_distance(vector<vector<int>>& matrix) {
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
    Solution sol;
    vector<vector<int>> answer = sol.shortest_distance(edges);

    for (auto& e : answer) {
        for (int i = 0; i < e.size(); i++) {
            cout << e[i] << " ";
        }
        cout << endl;
    }
}