#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int solve(vector<int> &arr, int target, int s, int e) {
        if (s > e) return -1;

        int mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return solve(arr, target, s, mid - 1);
        } else {
            return solve(arr, target, mid + 1, e);
        }
    }
    int binarySearch(vector<int> &arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        return solve(arr, target, s, e);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 4, 6, 8, 12, 14, 18, 20};
    int result = sol.binarySearch(arr, 18);
    cout << "Element index: " << result << endl;
    return 0;
}
