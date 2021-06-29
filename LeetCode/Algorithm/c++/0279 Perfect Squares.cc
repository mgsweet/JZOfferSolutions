class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
      for (int j = 1; i - j * j >= 0; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};