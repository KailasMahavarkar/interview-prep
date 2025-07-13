#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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
    void unionSet(int X, int Y) {
        int parentX = find(X);
        int parentY = find(Y);

        if (parentX == parentY) {
            return;
        }

        if (size[parentX] >= size[parentY]) {
            // more size -> make it a parent
            // in this case size[parentX] has more nodes than size[parentY]
            // so its ideal if we reduce it stress on parentX
            parent[parentY] = parentX;
            size[parentX] += size[parentY];
        } else {
            parent[parentX] = parentY;
            size[parentY] += size[parentX];
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }
};

int main() {
    DSU sol(8);
    sol.unionSet(0, 1);
    sol.unionSet(2, 3);
    sol.unionSet(4, 5);
    sol.unionSet(6, 7);
    sol.unionSet(0, 2);
    cout << sol.find(3) << endl;
    return 0;
}
