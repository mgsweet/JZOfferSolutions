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
      update_min(dp, i_2, i_3, i_5);
      while (dp[i_2] * 2 <= *(dp.end() - 1)) {
        ++i_2;
      }
      while (dp[i_3] * 3 <= *(dp.end() - 1)) {
        ++i_3;
      }
      while (dp[i_5] * 5 <= *(dp.end() - 1)) {
        ++i_5;
      }
    }
    return dp[n - 1];
  }

  static void update_min(vector<int> &dp, int &i_2, int &i_3, int &i_5) {
    int *min_i = &i_2;
    int pi = 2;
    if (dp[*min_i] * pi > dp[i_3] * 3) {
      min_i = &i_3;
      pi = 3;
    }
    if (dp[*min_i] * pi > dp[i_5] * 5) {
      min_i = &i_5;
      pi = 5;
    }
    dp.push_back(dp[*min_i] * pi);
    *min_i += 1;
  }
};