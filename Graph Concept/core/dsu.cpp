#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
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
    //                    A  B  C  D  E  F  G  H
    vector<int> parent = {0, 1, 2, 3, 4, 5, 6, 7};
    sol.unionSet(parent, 0, 1);  // A -> B
    sol.unionSet(parent, 2, 3);  // C -> D
    sol.unionSet(parent, 4, 5);  // E -> F
    sol.unionSet(parent, 6, 7);  // G -> H
    sol.unionSet(parent, 0, 2);  // A -> C
    sol.unionSet(parent, 4, 6);  // E -> G
    sol.unionSet(parent, 0, 4);  // A -> E
    cout << sol.find(parent, 3) << endl;
    return 0;
}