#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SolutionLinearSearch {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }

        return letters[0];
    }
};

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (letters[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s == n ? letters[0] : letters[s];
    }
};

int main() {
    vector<char> arr = {'a', 'c', 'e', 'g', 'k', 'm', 'x', 'y'};
    char target = 'z';
    SolutionLinearSearch sol;
    cout << "ans -->" << sol.nextGreatestLetter(arr, target) << endl;
}
