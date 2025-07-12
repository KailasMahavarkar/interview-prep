#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
public:

    int DFS(unordered_map<int, vector<int>> adj, int current, int parent, vector<bool>& hasApple){
        for (auto &child: adj[current]){
            if (child == parent) continue;

            int time_from_my_child = DFS(adj, child, current, hasApple);
            if (time_from_my_child > 0 || hasApple[child]){
                time += time_from_my_child + 2;
            } 
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        
        for (auto &vec: edges){
            int parent = vec[0];
            int child = vec[1];

            adj[parent].push_back(child);
            adj[child].push_back(parent);
        }
        return DFS(adj, 0, -1, hasApple);
    }
};

int main(){
    Solution sol;
    int ans = sol.minTime(
        n=7,
        edges={{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}},
        hasApple={false,false,true,false,true,true,false}
    );
    cout << "answer -->" << ans << endl;
}