#include <bits/stdc++.h>
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

void printUMAP(unordered_map<int, int> &umap){
	 // Traversing an unordered map
  for (auto x : umap)
    cout << x.first << " " << 
            x.second << endl;
}

class Solution
{
public:
	int subarraysDivByK(vector<int> &nums, int k)
	{

		unordered_map<int, int> mp;

		// we have seen 0 atleast 1 times
		mp[0] = 1;

		int total = 0;
		int answer = 0;
		for (int i=0; i < nums.size(); i++){
			total += nums[i];

			int rem = total % k;

			if (mp[i] < 0){
				rem += k;
			}

			// check if rem is seen previously in map
			if (mp.find(rem) != mp.end()){
				answer += mp[rem];
			}

			mp[rem]++;
		}  

		printVector("nums -->", nums);
		printUMAP(mp);
		cout << "ans -->  " << answer << endl;

		return -1;
	}
};

int main()
{
	vector<int> nums = {4, 5, 0, -2, -3, 1};
	Solution sol;
	sol.subarraysDivByK(nums, 5);
}