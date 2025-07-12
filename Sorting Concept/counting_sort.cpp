#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

vector<int> countingSort(vector<int> arr) {
    int n = arr.size();
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(maxElement + 1, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return output;
}

int main() {
}