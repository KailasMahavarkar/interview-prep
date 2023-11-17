#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> nums) {
    for (auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

int partition(int low, int high, vector<int> &nums) {
    int pivotValue = nums[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (nums[i] <= pivotValue && i < high) {
            i++;
        }

        while (nums[j] > pivotValue && j > low) {
            j--;
        }

        if (i < j) swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickSort(int low, int high, vector<int> &nums) {
    if (low < high) {
        int pIndex = partition(low, high, nums);
        quickSort(low, pIndex - 1, nums);
        quickSort(pIndex + 1, high, nums);
    }
}

int main() {
    vector<int> nums = {3, 1, 4, 2, 6};
    quickSort(0, nums.size() - 1, nums);
    printVector(nums);
}