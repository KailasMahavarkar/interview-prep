#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

typedef pair<int, int> pi;

// Approach-1 (Normal)
// TC : O(nlogn)
// SC : O(n)
class Solution {
   public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap; 
        int fuel = startFuel;
        int stops = 0;
        int index = 0;

        while (fuel < target) {
            while (index < stations.size() && stations[index][0] <= fuel) {
                maxHeap.push(stations[index][1]);
                index++;
            }

            if (maxHeap.empty()) {
                return -1;

            }   
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }

        return stops;
    }
};

int main() {
    int target = 12;
    int startFuel = 2;
    vector<vector<int>> stations = {
        {3, 3},
        {4, 4},
        {5, 8},
        {6, 5},
        {7, 2},
        {9, 2},
        {10, 2},
        {12, 3}};
    Solution sol;
    int minSteps = sol.minRefuelStops(target, startFuel, stations);
    cout << "min steps --> " << minSteps << endl;
}
