#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 2, 1, 3};
    int element = 0;
    for (auto num : nums) {
        element = element ^ num;
    }
    cout << element << endl;
}