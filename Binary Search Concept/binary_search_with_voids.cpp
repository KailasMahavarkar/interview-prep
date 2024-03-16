#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int binarySearchVoid(vector<int> &arr, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == -1) {
                int rightSide = binarySearchVoid(arr, mid + 1, e, target);
                int leftSide = binarySearchVoid(arr, s, mid - 1, target);
                return rightSide == -1 ? leftSide : rightSide;
            }

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

// int main() {
//     vector<int> arr = {1, 3, -1, 4, 5, -1, 6};
//     Solution sol;
//     int s = 0;
//     int e = arr.size();
//     int ans = sol.binarySearchVoid(arr, s, e, 6);
//     cout << "ans --> " << ans << endl;
// }

int binarySearchSkipNeg(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        while (start <= end && arr[start] == -1) {
            start++;
        }

        while (start <= end && arr[end] == -1) {
            end--;
        }

        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

int main() {
    // Example usage:
    vector<int> arr = {-1, -1, 2, 3, 4, -1, -1, -1, 8};
    int target = 4;
    int result = binarySearchSkipNeg(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}
