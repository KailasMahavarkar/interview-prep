#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printVector(string tag, vector<int> arr)
{
    cout << tag << " --> ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << "capacity: " << arr.capacity() << endl;
    cout << tag << " size: " << arr.size() << endl;
}


class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> answer = {};
        sort(nums.begin(), nums.end());


        for (int i=1; i < nums.size(); ++i){
            nums[i] += nums[i-1];
        }





        // printVector("nums", nums);
        return answer;
    }
};

    // def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
    //     nums.sort()
    //     prefix_sum_list = [0 for _ in nums]

    //     for i, num in enumerate(nums):
    //         prefix_sum_list[i] = prefix_sum_list[i-1] + num

        
    //     ans = [0 for _ in range(len(queries))]
    //     for i, query in enumerate(queries):
    //         ans[i] = bisect.bisect_right(prefix_sum_list, query)

    //     return ans
    //     print(ans)



int main()
{
    vector<int> nums = {4,5,2,1, 6, 13};
    vector<int> queries = {3, 10, 21, 2};
    vector<int> prefix_array = {};

    Solution sol;
    sol.answerQueries(nums, queries);
    
}