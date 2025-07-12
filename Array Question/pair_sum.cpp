#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : Unknown
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (two pointer)
// TC : O(n)
// SC : O(1)

void pairedSum(int sum, vector<int> arr, vector<pair<int, int>> &answer) {
    int s = 0;
    int e = arr.size() - 1;

    while (s < e) {
        if (arr[s] + arr[e] == sum) {
            answer.push_back({arr[s], arr[e]});
        }

        if (arr[s] + arr[e] < sum) {
            s++;
        } else {
            e--;
        }
    }
}

int main() {
    vector<int> arr = {2, 3, 4, -2, 6, 8, 9, 11};
    vector<pair<int, int>> answer;
    sort(arr.begin(), arr.end());
    pairedSum(6, arr, answer);

    for (auto x : answer) {
        cout << "(" << x.first << " " << x.second << ")"
             << " ";
    }
    cout << endl;
}