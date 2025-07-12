#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
public:
    int n;

    void dfs(vector<int>& edges, int startNode, vector<int> &distance,  vector<bool> &visited){
        visited[startNode] = true;

        int v = edges[startNode];
        if (v != -1 && !visited[v]){
            visited[v] = true;
            distance[v] = 1 + distance[startNode];
            dfs(edges, v, distance, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // get size of edges
        n = edges.size();

        vector<int> distance_1(n, INT_MAX);
        vector<int> distance_2(n, INT_MAX);
        vector<bool> visited_1(n, false);
        vector<bool> visited_2(n, false);
        distance_1[node1] = 0;
        distance_2[node2] = 0; 

        dfs(edges, node1, distance_1, visited_1);
        dfs(edges, node2, distance_2, visited_2);

        int minDistanceNode = -1;
        int minDistTillNow = INT_MAX;
        
        for (int i=0; i < n; i++){
            int maxD = max(distance_1[i], distance_2[i]);
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistanceNode;

    }
};