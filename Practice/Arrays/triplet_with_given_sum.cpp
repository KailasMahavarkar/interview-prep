#include <bits/stdc++.h>
using namespace std;

void printVI(vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input.at(i) << ' ';
    }
}

void printVVI(vector<vector<int>> &arr)
{
    for (const auto &row : arr)
    {
        for (const auto &s : row)
            cout << s << ' ';
        cout << endl;
    }
}

vector<int> tripletSum(vector<int> &arr, int sum){
    vector<int> answer;
    for (int i=0; i < arr.size(); i++){
        for (int j=i+1; j < arr.size(); j++){
            for (int k=j+1; k < arr.size(); k++){
                if (arr[i] + arr[j] + arr[k] == sum){
                    // cout << arr[i] << ": " << arr[j] << ": " << arr[k] << endl;
                    answer.push_back(arr[i]);
                    answer.push_back(arr[j]);
                    answer.push_back(arr[k]);
                    break;
                }
            }
        }
    }
    return answer;
}

int main()
{   
    vector<int> arr = {10, 20, 30, 40, 50};
    vector<int> ans = tripletSum(arr, 120);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << ' ';
    }
    return 1;
}