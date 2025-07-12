#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class DSU {
   public:
    vector<int> parent;
    vector<int> rank;

    void unionSet(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX == parentY) {
            return;
        }

        if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        } else if (rank[parentY] > rank[parentX]) {
            parent[parentX] = parentY;
        } else {
            parent[parentX] = parentY;
            rank[parentY]++;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void resize(int newSize) {
        parent.resize(newSize);
        rank.resize(newSize);

        // Initialize parent array
        for (int i = 0; i < newSize; i++) {
            parent[i] = i;
        }
    }
};

// Structure to represent an element
struct Element {
    string id;
    string prop1;
    string prop2;
    string prop3;

    Element(string id, string p1, string p2, string p3)
        : id(id), prop1(p1), prop2(p2), prop3(p3) {}
};

vector<vector<string>> findDuplicateGroups(vector<Element>& elements) {
    int n = elements.size();

    // Initialize DSU
    DSU dsu;
    dsu.resize(n);

    // Map property values to element indices
    unordered_map<string, vector<int>> propertyMap;

    // Process each element
    for (int i = 0; i < n; i++) {
        // Process each property of the current element
        vector<string> properties = {elements[i].prop1, elements[i].prop2, elements[i].prop3};

        for (const string& prop : properties) {
            if (propertyMap.find(prop) != propertyMap.end()) {
                // Union this element with all others that share this property
                for (int j : propertyMap[prop]) {
                    dsu.unionSet(i, j);
                }
                propertyMap[prop].push_back(i);
            } else {
                propertyMap[prop] = {i};
            }
        }
    }

    // Group elements by their representative (parent)
    unordered_map<int, vector<string>> groups;
    for (int i = 0; i < n; i++) {
        int parent = dsu.find(i);
        groups[parent].push_back(elements[i].id);
    }

    // Convert the map to a vector of vectors
    vector<vector<string>> result;
    for (const auto& [parent, ids] : groups) {
        result.push_back(ids);
    }

    return result;
}

// Example usage
int main() {
    vector<Element> elements = {
        Element("id1", "p1", "p2", "p3"),
        Element("id2", "p1", "p4", "p5"),
        Element("id3", "p6", "p7", "p8")};

    vector<vector<string>> duplicateGroups = findDuplicateGroups(elements);

    // Print the result
    cout << "Duplicate groups:" << endl;
    for (const auto& group : duplicateGroups) {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}