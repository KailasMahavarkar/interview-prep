#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        cout << "arr[" << s << "] -> " << arr[s] << " | arr[" << e << "] -> " << arr[e] << endl;
        cout << "mid --> " << mid << " | arr[" << mid << "] --> " << arr[mid] << endl;
        cout << "s -->" << s << endl;
        cout << "e -->" << e << endl;

        bool case1 = arr[mid] != mid + 1;
        bool case2 = arr[mid - 1] == mid;

        if (case1) {
            cout << "c1 | arr[mid] which is " << arr[mid] << " equals [mid + 1] which is " << mid + 1 << endl;
        }

        if (case2) {
            cout << "c2 | arr[mid - 1] which is " << arr[mid - 1] << " equals mid which is " << mid << endl;
        }

        // this code to to stop binary search
        // if we dont then we have to wait for either s or e to (halve and halve)
        // until s reaches e eventually
        if (arr[mid] != mid + 1 && arr[mid - 1] == mid) {
            return mid + 1;
        }

        if (arr[mid] == mid + 1) {
            s = mid + 1;
            cout << "abandon left" << endl;
        } else {
            e = mid - 1;
            cout << "abandon right" << endl;
        }

        cout << endl;
    }

    cout << "s: " << s << endl;
    cout << "e: " << e << endl;

    return s + 1;
}

int main() {
    vector<int> arr = {1, 2, 3};
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 9};
    // vector<int> arr = {1, 2, 4, 5, 6, 7, 8, 9};
    int missingNumber = findMissingNumber(arr);
    cout << "Missing number: " << missingNumber << endl;
    cout << endl;

    // int missingNumber = findMissingNumber(arr2);
    // cout << "Missing number: " << missingNumber << endl;

    return 0;
}