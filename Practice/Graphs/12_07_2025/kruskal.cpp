#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class DSU {
   public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unionSet(int x, int y) {
        int parentY = find(y);
        int parentX = find(x);

        if (parentY == parentX) {
            return;
        }

        // size[parentX] = 100
        // size[parentY] = 5
        if (size[parentX] >= size[parentY]) {
            parent[parentY] = parentX;
            size[parentX] += size[parentY];
        } else {
            parent[parentX] = parentY;
            size[parentY] += size[parentX];
        }
    }
};

class Solution {
   public:
    bool comparator(vector<int> &a, vector<int> &b) { return a[2] < b[2]; }

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b) {
            return comparator(a, b);
        });

        DSU dsu(V);
        int cost = 0, count = 0;

        for (auto &e : edges) {
            int x = e[0], y = e[1], w = e[2];
            if (dsu.find(x) != dsu.find(y)) {
                dsu.unionSet(x, y);
                cost += w;
                if (++count == V - 1)
                    break;
            }
        }
        return cost;
    }
};

int main() {
    vector<vector<int>> edges = {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}};
    Solution sol;
    cout << sol.kruskalsMST(4, edges);
    return 0;
}