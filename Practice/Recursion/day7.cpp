#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// power set -> arr[3] = {1,2,3}
// {}, {1} {2} {3} {1, 2} {1, 3} {2, 3} {1, 2, 3}
// elements in powerset is always 2^n

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void printVI(vi arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }cout << endl;
}

// https://youtu.be/V0IgCltYgg4?list=PLDzeHZWIZsTqBmRGnsCOGNDG5FY0G04Td&t=272
void solvePowerSet(vi nums, vi output, int index, vvi& ans)
{
    if (index >= nums.size()){
        printVI(output);
        ans.push_back(output);
        return;
    }

    // exclude wala call
    solvePowerSet(nums, output, index+1, ans);

    // include wala call
    int element = nums[index];
    output.push_back(element);
    solvePowerSet(nums, output, index+1, ans);

}

vvi powerSet(vi &nums)
{
    vvi ans;
    vi output;
    int index = 0;
    solvePowerSet(nums, output, index, ans);
    return ans;
}




int main()
{
    vi arr = {1, 2, 3, 4};
    powerSet(arr);
}