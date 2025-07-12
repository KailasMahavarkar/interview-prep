using namespace std;
#pragma GCC optimize("O3,unroll-loops")
class Solution {
   public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }

        int n = nums.size();
        vector<long> prefixSum;

        long total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            prefixSum.push_back(total);
        }

        // instead of filling (0 to k) and (n-k to n) as -1
        // we fill entire array and modify center part as we only care that
        // 0 ......... k ....... n-k ........ n
        vector<int> answer(n, -1);

        for (int i = k; i < n - k; i++) {
            int left_index = i - k;
            int right_index = i + k;
            long long sum = prefixSum[right_index];

            if (left_index > 0) {
                sum -= prefixSum[left_index - 1];
            }

            int avg = sum / (2 * k + 1);
            answer[i] = avg;
        }

        return answer;
    }
};
