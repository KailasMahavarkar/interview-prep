#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    void unionSet(vector<int> &parent, vector<int> &rank, int x, int y) {
        int x_parent = find(parent, x);
        int y_parent = find(parent, y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            // jiska rank jyada hoga vo daddy banega
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            // jiska rank jyada hoga vo daddy banega
            parent[x_parent] = y_parent;
        } else {
            // rank same hua toh kisi ek ko dusre ka daddy bana do
            // jisko bhi daddy banaya uska rank increment kardo
            parent[y_parent] = x_parent;  // y became daddy of x
            rank[x_parent]++;
        }
    }
    int find(vector<int> &parent, int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent, parent[x]);
    }
};

int main() {
    DSU sol;
    vector<int> parent = {0, 1, 2, 3};
    vector<int> rank = {0, 0, 0, 0};
    sol.unionSet(parent, rank, 1, 2);
    sol.unionSet(parent, rank, 3, 1);

    // sol.unionSet(parent, rank, 2, 0);

    // sol.unionSet(parent, rank, 2, 3);
    // sol.unionSet(parent, rank, 4, 5);
    // sol.unionSet(parent, rank, 6, 7);
    // sol.unionSet(parent, rank, 0, 2);
    // sol.unionSet(parent, rank, 4, 6);
    // sol.unionSet(parent, rank, 0, 4);

    // print rank of each node
    for (int i = 0; i < parent.size(); i++) {
        cout << "rank of " << i << " is " << rank[i] << endl;
    }

    cout << sol.find(parent, 2) << endl;
    return 0;
}