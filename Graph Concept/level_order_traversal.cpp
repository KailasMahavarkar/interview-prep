#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to perform level-order traversal
vector<vector<int>> levelOrderTraversal(vector<vector<int>>& graph, int startNode) {
    vector<vector<int>> result;  // Stores nodes level-wise
    unordered_set<int> visited;  // Set to track visited nodes
    queue<int> q;                // Queue for BFS

    q.push(startNode);  // Start from the given node
    visited.insert(startNode);

    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes at the current level
        vector<int> currentLevel;  // Stores nodes at this level

        for (int i = 0; i < levelSize; ++i) {
            int node = q.front();
            q.pop();
            currentLevel.push_back(node);

            // Add all unvisited neighbors to the queue
            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        result.push_back(currentLevel);  // Add current level to result
    }

    return result;
}

int main() {
    // Graph represented as an adjacency list
    vector<vector<int>> graph = {
        {},      // Node 0 (dummy node, graph starts from node 1)
        {2, 3},  // Node 1 connected to 2, 3
        {4, 5},  // Node 2 connected to 4, 5
        {6},     // Node 3 connected to 6
        {},      // Node 4
        {},      // Node 5
        {}       // Node 6
    };

    int startNode = 1;  // Starting node for traversal
    vector<vector<int>> result = levelOrderTraversal(graph, startNode);

    // Print the result
    cout << "Level Order Traversal:" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Level " << i + 1 << ": ";
        for (int node : result[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
