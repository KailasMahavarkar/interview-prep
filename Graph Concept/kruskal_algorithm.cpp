#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int nodeX = find(x);
        int nodeY = find(y);

        // both belong to different component no need to merge
        if (nodeX == nodeY) {
            return;
        }

        // check rank
        if (rank[nodeX] > rank[nodeY]) {
            parent[nodeY] = nodeX;  // x rank is more so its papa
        } else if (rank[nodeX] < rank[nodeY]) {
            parent[nodeX] = nodeY;
        } else {
            // both rank are same (make any one as parent)
            parent[nodeY] = nodeX;
            rank[nodeX]++;
        }
    }

    int kruskal(vector<vector<int>> &vec) {
        int sum = 0;

        for (auto &temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int uParent = find(u);
            int vParent = find(v);

            if (uParent != vParent) {
                unionSet(u, v);
                sum += wt;
            }
        }

        return sum;
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        parent.resize(V);
        rank.resize(V, 0);
        vector<vector<int>> vec;

        // DSU: initally all vertices are seperated and each of them is itself parent
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < V; i++) {
            for (auto &temp : adj[i]) {
                int u = i;
                int v = temp[0];
                int d = temp[1];

                vec.push_back({u, v, d});
            }
        }

        sort(vec.begin(), vec.end(), [&](auto &x, auto &y) {  // ELOG(E)
            return x[2] < y[2];
        });

        return kruskal(vec);
    }
};

int main() {
    int V = 3;  // Number of vertices
    vector<vector<int>> adj[V];

    adj[0].push_back({0, 1, 5});
    adj[1].push_back({1, 2, 3});
    adj[2].push_back({0, 2, 1});

    Solution sol;
    int result = sol.spanningTree(V, adj);
    cout << "Sum of weights of the minimum spanning tree: " << result << endl;
    return 0;
}
