#include <bits/stdc++.h>
using namespace std;

// s -> given sum (10 + 40)
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                // get minimum
                temp.push_back(min(arr[i], arr[j]));
                // get maximum
                temp.push_back(max(arr[i], arr[j]));
                answer.push_back(temp);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};

    vector<vector<int>> ans = pairSum(arr, 50);

    for (const auto &row : ans)
    {
        for (const auto &s : row)
            cout << s << ' ';
        cout << endl;
    }

    cout << "done" << endl;

    return 0;
}