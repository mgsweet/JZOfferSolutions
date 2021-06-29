class Solution {
public:
  static int numTilings(int N) {
    int dp[3] = {1, 1, 2};
    if (N < 3) {
      return dp[N];
    }
    for (int i = 3; i <= N; ++i) {
      int tmp = dp[2];
      dp[2] = (2 * dp[2] % (int) (pow(10, 9) + 7) + dp[0]) % (int) (pow(10, 9) + 7);
      dp[0] = dp[1];
      dp[1] = tmp;
    }
    return dp[2];
  }
};