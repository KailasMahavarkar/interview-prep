#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();

        vector<set<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        set<int> appeared;

        // Build graph from sequences
        for (auto& seq : sequences) {
            // Track which numbers appeared in sequences
            for (int num : seq) {
                appeared.insert(num);
            }

            // Add edges between consecutive elements
            for (int i = 0; i < seq.size() - 1; i++) {
                int from = seq[i];
                int to = seq[i + 1];

                // Only add edge if it doesn't exist already (avoid duplicate edges)
                if (graph[from].find(to) == graph[from].end()) {
                    graph[from].insert(to);
                    indegree[to]++;
                }
            }
        }

        // Check if all numbers from nums appeared in sequences
        for (int num : nums) {
            if (appeared.find(num) == appeared.end()) {  // we could not find the number in the sequences
                return false;
            }
        }

        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            // KEY CHECK: If more than one node has indegree 0, multiple orderings possible
            if (q.size() > 1) {
                return false;
            }

            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result.size() == n && result == nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sequences = {{1, 2}, {1, 3}};
    cout << sol.sequenceReconstruction(nums, sequences) << endl;
    return 0;
}

// 444. Sequence Reconstruction
// You are given an integer array `nums` of length `n` where `nums` is a permutation of integers in the range `[1, n]`. You are also given a 2D integer array `sequences` where `sequences[i]` is a subsequence of `nums`.
// Check whether `nums` is the shortest supersequence of `sequences`. A shortest supersequence is a sequence with the shortest length such that all sequences in `sequences` are subsequences of it.
// A subsequence is a sequence that can be derived from the original sequence by deleting some or no elements without changing the order of the remaining elements.
// Return `true` if `nums` is the only shortest supersequence of `sequences`, or `false` otherwise.

// Example 1:
// Input: nums = [1,2,3], sequences = [[1,2],[1,3]]
// Output: false
// Explanation: There are two shortest supersequences: [1,2,3] and [1,3,2].
// The sequence [1,2,3] has subsequences [1,2] and [1,3].
// The sequence [1,3,2] has subsequences [1,2] and [1,3].
// Since nums is not the only shortest supersequence, we return false.

// Example 2:
// Input: nums = [1,2,3], sequences = [[1,2]]
// Output: false
// Explanation: The shortest supersequence is [1,2].
// The sequence [1,2,3] has more elements than necessary, so it is not a shortest supersequence.

// Example 3:
// Input: nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
// Output: true
// Explanation: The shortest supersequence is [1,2,3].
// The sequence [1,2,3] is the only supersequence that has [1,2], [1,3], and [2,3] as subsequences.

// Constraints:
// - `n == nums.length`
// - `1 <= n <= 10^4`
// - `nums` is a permutation of all the integers in the range `[1, n]`
// - `1 <= sequences.length <= 10^4`
// - `1 <= sequences[i].length <= 10^4`
// - `1 <= sum(sequences[i].length) <= 10^5`
// - `1 <= sequences[i][j] <= n`
// - All the arrays of `sequences` are unique.
// - `sequences[i]` is a subsequence of `nums`.
