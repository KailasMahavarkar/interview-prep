#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool checkPossible(vector<int>& time, long long givenTime, int totalTrips) {
        long long acutalTrips = 0;

        for (int &t : time) {
            // number of trips for each bus
            // lets say givenTime is 4 and time array is [2, 4]
            // thus actualTrips will be = (4 / 2) + (4 / 4) = 3

            // Now, lets say givenTime is 8 and time array is [2, 4]
            // thus actualTrips will be = (8 / 2) + (8 / 4) = (4 + 2) = 6
            // in leetcode try input -> [2, 4] & 6 -> answer(8)
            acutalTrips += givenTime / t;
        }

        // in bruteforce we tried each all times for entire array and
        // checked if sum of all times at given time is equal to totalTrips

        // in binary search instead of checking the entire array repeatedly 
        // we check only for 'k' times (where k < n) 
        return acutalTrips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l = 1;
        long long r = (long long) *min_element(begin(time), end(time)) * totalTrips;
        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (checkPossible(time, mid, totalTrips)) {
                // mid time me possible hai or mid time se less me possible h
                // search space is reduced towards left but mid is also a candidate
                // for given answer
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    int ans = sol.minimumTime(nums, 5);
    cout << "ans: " << ans << endl;
}