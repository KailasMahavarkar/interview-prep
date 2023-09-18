#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    int find(vector<int> &parent, int x) {
        if (parent[x] == x)
            return x;

        return find(parent, parent[x]);
    }
    void unionSet(vector<int> &parent, int X, int Z) {
        int x = find(parent, X);
        int y = find(parent, Z);

        if (x == y)
            return;

        parent[y] = x;
    }
};

int main() {
    DSU sol;
    vector<int> parent = {0, 1, 2, 3, 4, 5, 6, 7};
    sol.unionSet(parent, 0, 1);
    sol.unionSet(parent, 2, 3);
    sol.unionSet(parent, 4, 5);
    sol.unionSet(parent, 6, 7);
    sol.unionSet(parent, 0, 2);
    sol.unionSet(parent, 4, 6);
    sol.unionSet(parent, 0, 4);
    cout << sol.find(parent, 3) << endl;
    return 0;
}