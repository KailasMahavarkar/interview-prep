#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "capacity: " << arr.capacity() << endl;
    cout << "size: " << arr.size() << endl;
}

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> answer = {};
        sort(nums.begin(), nums.end());

        printVector(nums);
        return answer;
    }
};

int main()
{
    vector<int> nums = {10, 20, 30, 40, 50};
    int half_size = (nums.size() / 2);

    vector<int> split_low(nums.begin(), nums.begin() + half_size);
    vector<int> split_high(nums.begin() + half_size, nums.end());

    vector<int> merge_vec;


    merge_vec.reserve(split_low.size() + split_high.size()); 
    merge_vec.insert(merge_vec.end(), split_low.begin(), split_low.end() );
    merge_vec.insert(merge_vec.end(), split_high.begin(), split_high.end());

    // vector<int> queries = {3, 10, 21};
    printVector(merge_vec);

    // Solution sol;
    // sol.answerQueries(nums, queries);
}