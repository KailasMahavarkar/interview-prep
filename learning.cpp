#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve() {
        vector<int> boxes = {1, 1, 1, 2, 2, 2};
        int n = boxes.size();

        // int count = 1;
        // int y = 0;
        // while (y + 1 < n && boxes[y] == boxes[y + 1]) {
        //     y++;
        //     count++;
        // }
        // y += 1;

        int count = 1;
        int y = 1;
        while (y <= n && boxes[y] == boxes[y - 1]) {
            y++;
            count++;
        }

        cout << "count: " << count << " | y: " << y << endl;

        return -1;
    }
};

int main() {
    Solution sol;
    int ans = sol.solve();
    cout << "int ->" << ans << endl;
    return 0;
}
