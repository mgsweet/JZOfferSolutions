class Solution {
public:
  static int nthUglyNumber(int n) {
    if (n <= 0) return 0;
    vector<int> dp;
    int i_2 = 0;
    int i_3 = 0;
    int i_5 = 0;
    dp.push_back(1);
    while (dp.size() < n) {
      dp.push_back(min(dp[i_2] * 2, min(dp[i_3] * 3, dp[i_5] * 5)));
      if (*(dp.end() - 1) == dp[i_2] * 2) ++i_2;
      if (*(dp.end() - 1) == dp[i_3] * 3) ++i_3;
      if (*(dp.end() - 1) == dp[i_5] * 5) ++i_5;
    }
    return dp[n - 1];
  }
};