#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    void unionSet(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (size[x_parent] >= size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }
};

int main() {
    DSU dsu(6);
    dsu.unionSet(0, 1);
    dsu.unionSet(0, 2);

    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
        cout << "Not in same component" << endl;
    }

    dsu.unionSet(0, 3);
    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
        cout << "Not in same component" << endl;
    }
}