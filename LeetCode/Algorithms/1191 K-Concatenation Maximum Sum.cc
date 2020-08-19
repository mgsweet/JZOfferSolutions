class Solution {
public:
    static int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (arr.empty() || k == 0) return 0;
        const long long M = 1e9 + 7;
        // Case 1, find best subarray sum
        long long sum = 0;
        long long max_subarr_sum = 0;
        for (int num : arr) {
          if ((sum + num) % M > 0) {
            sum = (sum + num) % M;
          } else {
            sum = 0;
          };
          max_subarr_sum = max(max_subarr_sum, sum);
        }
        // Case 2
        sum = 0;
        long long max_start = 0;
        for (int num: arr) {
          sum = (sum + num) % M;
          max_start = max(sum, max_start);
        }
        sum = 0;
        long long max_end = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
          sum = (sum + arr[i]) % M;
          max_end = max(sum, max_end);
        }
        // Judge
        if (k == 1) return max_subarr_sum;
        if (k == 2) return max(max_subarr_sum, (max_start + max_end) % M);
        else {
          long long total_sum = 0;
          for (int i = 0; i < k - 2; ++i) {
            total_sum = (total_sum + sum) % M;
          }
          if (total_sum < 0) total_sum = 0;
          total_sum = ((total_sum + max_start) % M + max_end) % M;
          return max(max_subarr_sum, total_sum);
        }
    }
};