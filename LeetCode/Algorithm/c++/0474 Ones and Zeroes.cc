class Solution {
public:
  static int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
    for (auto str: strs) {
      int zero_count = count(str.begin(), str.end(), '0');
      int one_count = str.size() - zero_count;
      for (int i = m; i >= zero_count; --i) {
        for (int j = n; j >= one_count; --j) {
          memo[i][j] = max(memo[i][j], memo[i - zero_count][j - one_count] + 1);
        }
      }
    }
    return memo[m][n];
  }
};