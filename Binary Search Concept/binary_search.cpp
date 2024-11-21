#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int binarySearch(vector<int> &arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (target > arr[mid]) {
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
    vector<int> arr = {-1, -1, 2, 3, 4, -1, -1, -1, 8};
    int target = 4;
    int result = sol.binarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}
