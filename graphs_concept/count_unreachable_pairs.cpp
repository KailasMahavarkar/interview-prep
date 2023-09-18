#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> rank;
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        // find x's parent
        int x_parent = find(x);
        // fint y's parent
        int y_parent = find(y);

        // both x and y belong to same set
        // no need to merge
        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            // x has more rank -> make it parent of y
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];

            unionSet(u, v);
        }

        // map to store (parent -> size)
        unordered_map<int, int> hmap;


        // build vector -> size map
        // store i'th child will have how many childrens
        for (int i = 0; i < n; i++) {
            int parent = find(i);
            hmap[parent]++;
        }

        long long result = 0;
        long long remainingNode = n;

        for (auto& it : hmap) {
            long long size = it.second;
            result += (size) * (remainingNode - size);
            remainingNode -= size;
        }

        return result;
    }
};