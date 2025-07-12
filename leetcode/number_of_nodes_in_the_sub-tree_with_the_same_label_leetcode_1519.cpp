#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
public:

    vector<int> DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<int> &result, string &labels){
        // 26 characters -> a-z
        vector<int> myCount(26, 0);

        char myLabel = labels[curr];
        myCount[myLabel - 'a'] = 1; 

        for (int &child: adj[curr]){
            if (child == parent) continue;

            vector<int> child_count(26, 0);
            child_count = DFS(adj, child, curr, result, labels);

            for (int i=0; i < 26; i++){
                myCount[i] += child_count[i];
            }
        }
        result[curr] = myCount[myLabel - 'a'];
        return myCount;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adj;

        for (auto &vec: edges){
            int parent = vec[0];
            int child = vec[1];

            adj[parent].push_back(child);
            adj[child].push_back(parent);
        }
        vector<int> result(n, 0);

        // adj | curr | parent | result |labels
        DFS(adj, 0, -1, result, labels);
        return result;
    }
};


int main(){
    Solution sol;
    sol.countSubTrees(5, {{0,1},{0,2},{1,3},{0,4}}, "aabab")
}