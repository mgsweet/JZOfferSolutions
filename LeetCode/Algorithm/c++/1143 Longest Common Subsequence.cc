class Solution {
public:
  static int longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty()) return 0;
    vector<int> memo(text2.size() + 1, 0);
    int pre, up;
    for (int i = 1; i <= text1.size(); ++i) {
      pre = 0;
      for (int j = 1; j <= text2.size(); ++j) {
        up = memo[j];
        if (text1[i - 1] == text2[j - 1]) {
          memo[j] = pre + 1;
        } else {
          memo[j] = max(up, memo[j - 1]);
        }
        pre = up;
      }
    }
    return memo[text2.size()];
  }
};