#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int binarySearch(vector<int> &arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {  // jab tak "s" kam h "e" se
            mid = s + (e - s) / 2;

            if (target == arr[mid]) {
                return mid;
            }

            if (target > arr[mid]) {  // target is more | arr[mid] is less
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 4, 6, 8, 12, 14, 18, 20};
    int result = sol.binarySearch(arr, 18);
    cout << "Element found at index: " << result << endl;
    return 0;
}
