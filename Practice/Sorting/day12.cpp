#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> nums) {
    for (auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

int partition(int s, int e, vector<int> &nums) {
    int count = 0;
    int pivotValue = nums[s];

    // count all elements less than pivot
    for (int i = s + 1; i < nums.size(); i++) {
        if (nums[i] < pivotValue) {
            count++;
        }
    }

    // swap the first element with [counter + s]
    int pivotIndex = s + count;
    swap(nums[pivotIndex], nums[s]);

    int i = s;
    int j = e;

    // sort the element such that left half of array is sorted
    while (i < pivotIndex && j > pivotIndex) {
        cout << "i " << i << " | j " << j << endl;

        while (nums[i] < pivotValue) {
            i++;
        }
        while (nums[j] > pivotValue) {
            j--;
        }

        // both pointers are 'stale' -> not moving thus swap
        // before swapping check if prev condition is violated
        // since we moved i and j | there is possibility the j is on pivot
        if (i < pivotIndex && j > pivotIndex) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int s, int e, vector<int> &nums) {
    if (s >= e) {
        return;
    }

    int p = partition(s, e, nums);
    // cout << p << endl;
    quickSort(s, p - 1, nums);
    quickSort(p + 1, e, nums);
}

int main() {
    vector<int> nums = {3, 1, 4, 2, 6};
    quickSort(0, nums.size() - 1, nums);
    printVector(nums);
}