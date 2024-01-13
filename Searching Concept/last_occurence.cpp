#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

vector<int> binarySearch(vector<int> arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    int first = -1;
    int last = -1;

    // to find first occurence
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (target == arr[mid]) {
            first = mid;
            e = mid - 1;
        }

        else if (arr[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    s = 0;
    e = arr.size() - 1;

    // to find last occurence
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (target == arr[mid]) {
            last = mid;
            s = mid + 1;
        }

        else if (arr[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    vector<int> result({first, last});
    return result;
}

int main() {
    vector<int> arr = {2, 5, 7, 7, 7, 7, 9, 20};
    vector<int> ans = binarySearch(arr, 7);

    cout << "first: " << ans[0] << endl;
    cout << "last: " << ans[1] << endl;
}