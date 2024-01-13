#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (target == arr[mid]) {
            return mid;
        }

        else if (arr[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 5, 7, 7, 7, 7, 9, 20};

    cout << binarySearch(arr, 7) << endl;
}