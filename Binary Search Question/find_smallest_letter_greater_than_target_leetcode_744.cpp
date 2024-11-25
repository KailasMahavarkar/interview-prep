#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0;
        int e = letters.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (letters[mid] <= target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s > letters.size() : letters[0] : letters[s];
    }
};

int main() {
    vector<char> arr = {'x', 'x', 'y', 'y'};
    char target = 'z';
    Solution sol;
    cout << "ans -->" << sol.nextGreatestLetter(arr, target) << endl;
}
