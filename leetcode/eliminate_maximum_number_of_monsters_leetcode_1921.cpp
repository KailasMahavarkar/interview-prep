#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n, 0);

        for (int i = 0; i < n; i++) {
            // speed = distance / time -> time = distance / speed;
            time[i] = dist[i] / speed[i];
        }

        int killedMonsters = 1;  // since gun was initally charged
        int timePassed = 1;

        // sort time array
        sort(time.begin(), time.end());

        for (int i = 1; i < n; i++) {
            if (time[i] - timePassed <= 0) {
                return killedMonsters;
            } else {
                killedMonsters++;
            }

            timePassed++;  // time will increase by 1 unit
        }

        return killedMonsters;
    }
};

int main() {
    vector<int> dist = {1, 3, 4};
    vector<int> speed = {1, 1, 1};
    Solution sol;
    int ans = sol.eliminateMaximum(dist, speed);
    cout << "ans -->" << ans << endl;
}