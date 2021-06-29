class Solution {
public:
  static int findNumberOfLIS(vector<int>& nums) {
    typedef pair<int, int> II;
    vector<II> dp(nums.size(), II(1, 1));
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[i].first < dp[j].first + 1) {
            dp[i].first = dp[j].first + 1;
            dp[i].second = dp[j].second;
          } else if (dp[i].first == dp[j].first + 1) {
            dp[i].second += dp[j].second;
          }
        }
      }
    }
    int max_len = 0, res = 0;
    for (int i = 0; i < dp.size(); ++i) {
      if (max_len < dp[i].first) {
        max_len = dp[i].first;
        res = dp[i].second;
      } else if (max_len == dp[i].first) {
        res += dp[i].second;
      }
    }
    return res;
  }
};