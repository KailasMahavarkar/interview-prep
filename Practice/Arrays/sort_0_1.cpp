#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOne(int arr[], int n)
{

    int i = 0, j = n - 1;

    while (i < j)
    {
        // 0 1 0 1
        // s1 -> 0 1 0 1
        //       i     j
        // s2 -> 0 1 0 1
        //         i j
        // s3 -> 0 0 1 1
        //         j i       [swap]

        while (arr[i] == 0) 
        {
            i++;
        }
        while (arr[j] == 1 && i < j)
        {
            j--;
        }

        if (arr[i] == 1 && arr[j] == 0 && i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};
    sortOne(arr, 8);

    for (auto x : arr)
        cout << x;
    return 0;
}