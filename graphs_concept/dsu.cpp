#include <bits/stdc++.h>
using namespace std;

void Union(int x, int y, vector<int> &parent, vector<int> &rank) {
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

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
        parent[x_parent] = y_parent; // y became daddy of x
        rank[y_parent]++;
    }
}

void find(int x, vector<int> &parent) {
    if (i == parent[i]) {
        return i;
    }

    // path compression
    return parent[i] = find(parent[i], parent);
}