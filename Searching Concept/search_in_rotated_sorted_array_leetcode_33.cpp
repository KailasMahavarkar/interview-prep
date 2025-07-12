using namespace std;
#pragma GCC optimize("O3,unroll-loops")
class Solution {
   public:
    int search(vector<int> &arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = (s + e) / 2;

        while (s <= e) {
            if (arr[mid] == target) {
                return mid;
            }

            // is left half sorted
            if (arr[s] <= arr[mid]) {
                // check if target lies in left half
                if (target >= arr[s] && target <= arr[mid]) {
                    // eliminate right side
                    e = mid - 1;
                } else {
                    // eliminate left half
                    s = mid + 1;
                }
            }
            // right side is sorted
            else {
                if (target >= arr[mid] && target <= arr[e]) {
                    // eliminate left side
                    s = mid + 1;
                } else {
                    // eliminate right side
                    e = mid - 1;
                }
            }

            // re-calculate mid
            mid = s + (e - s) / 2;
        }
        return -1;
    }
};

int main() {
    // dry run this code on book or on whiteboard
    vector<int> arr = {5, 6, 7, 8, 9, 10, 11, 1, 2, 3};
    int target = 0;

    Solution sol;
    cout << sol.search(arr, target) << endl;
    return 0;
}
