class Solution {
public:
  static double soupServings(int N) {
    N = N / 25 + (N % 25 > 0 ? 1 : 0);
    if (N > 500) return 1;
    double dp[500][500];
    return assistFunc(dp, N, N);
  }

  static double assistFunc(double dp[500][500], int a, int b) {
    if (a <= 0 && b <= 0) return 0.5;
    if (a <= 0) return 1;
    if (b <= 0) return 0;
    if (dp[a][b] > 0) return dp[a][b];
    dp[a][b] = 0.25 * (assistFunc(dp, a - 4, b) + assistFunc(dp, a - 3, b - 1) +
                       assistFunc(dp, a - 2, b - 2) + assistFunc(dp, a - 1, b - 3));
    return dp[a][b];
  }
};