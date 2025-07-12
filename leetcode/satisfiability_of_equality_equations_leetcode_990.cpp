#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
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
    void union_set(int x, int y) {
        // a == b, e == c, b == c | equal to wale case me union karna h
        // a != e  | not equal to case me find karna h

        int x_parent = find(x);
        int y_parent = find(y);

        // when both parent are same
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        // fill rank and parent
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        // pehle sabko union karo jisme '=' sign ho
        for (string& s : equations) {
            if (s[1] == '=') {
                union_set(s[0] - 'a', s[3] - 'a');
            }
        }

        for (string& s : equations) {
            if (s[1] == '!') {
                if (find(s[0] - 'a') == find(s[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};