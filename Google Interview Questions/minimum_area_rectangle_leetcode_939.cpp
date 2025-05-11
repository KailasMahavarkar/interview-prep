#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

class Solution {
   public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> mp;

        for (auto point : points) {
            int x = point[0];
            int y = point[1];
            mp[x].push_back(y);
        }

        unordered_map<string, int> ump;
        int ans = INT_MAX;

        for (auto& [x, ys] : mp) {
            sort(ys.begin(), ys.end());
            int n = ys.size();

            for (int i = 0; i < n; ++i) {
                int y1 = ys[i];

                for (int j = i + 1; j < n; ++j) {
                    int y2 = ys[j];
                    string pt = to_string(y1) + "_" + to_string(y2);

                    if (ump.count(pt)) {
                        ans = min(ans, (x - ump[pt]) * (y2 - y1));
                    }

                    ump[pt] = x;
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    vector<vector<int>> points = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
    Solution sol;
    int ans = sol.minAreaRect(points);
    cout << "ans --> " << ans << endl;
}
