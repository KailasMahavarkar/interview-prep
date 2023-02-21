#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vct;

void printVCT(vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input.at(i) << ' ';
    }
}

vct findArrayIntersection(vct &arr1, int n, vct &arr2, int m)
{
    int i = 0, j = 0;
    vct ans;

    // meaning if i is less than n also j is less than m
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            // perform pushback
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}

int main()
{
    vct arr1 = {10, 20, 30, 40, 10};
    vct arr2 = {10, 20, 30, 40};

    printVCT(findArrayIntersection(arr1, 6, arr2, 7));

    return 1;
}

