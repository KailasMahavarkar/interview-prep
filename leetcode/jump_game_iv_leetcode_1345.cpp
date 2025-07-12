#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();  // last index -> n - 1

        unordered_map<int, vector<int>> hmap;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            hmap[arr[i]].push_back(i);  // value -> {index1, index2...}
        }

        queue<int> que;
        que.push(0);
        visited[0] = true;

        int steps = 0;

        while (!que.empty()) {
            int size = que.size();

            // check current level
            while (size--) {
                int curr = que.front();
                que.pop();

                if (curr == n - 1) {
                    return steps;
                }

                int left = curr - 1;
                int right = curr + 1;

                if (left >= 0 && !visited[left]) {
                    que.push(left);
                    visited[left] = true;
                }

                if (right < n && !visited[right]) {
                    que.push(right);
                    visited[right] = true;
                }

                for (int& idx : hmap[arr[curr]]) {
                    if (!visited[idx]) {
                        que.push(idx);
                        visited[idx] = true;
                    }
                }

                // this is game, since if we dont erase we will enter values
                // again and again in que -> dry run for example [7, 7, 2, 1, 7, 7, 7]
                hmap.erase(arr[curr]);
            }
            steps++;
        }

        return -1;
    }
};

int main() {
    int arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    Solution sol;
    int ans = sol.minJumps(arr);
    cout << "ans: " << ans << endl;
}