#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> in_degree(
            numCourses, 0);                     // in_degree[i] = number of prerequisites for course i
        vector<vector<int>> graph(numCourses);  // graph[i] = list of courses that
                                                // course i is a prerequisite for

        for (auto &prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]]++;
        }

        queue<int> q;  // queue of courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            for (int neighbor : graph[course]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return result;
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    Solution sol;
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    for (int course : result) {
        cout << course << " ";
    }
    cout << endl;
    return 0;
}