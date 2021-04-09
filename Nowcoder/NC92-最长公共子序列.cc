class Solution {
public:
  /**
   * longest common subsequence
   * @param s1 string字符串 the string
   * @param s2 string字符串 the string
   * @return string字符串
   */
  static string LCS(string s1, string s2) {
    vector<string> memo(s2.size() + 1, "");
    string pre, tmp;
    for (int i = 1; i <= s1.size(); ++i) {
      pre = "";
      for (int j = 1; j <= s2.size(); ++j) {
        tmp = memo[j];
        if (s1[i - 1] == s2[j - 1]) {
          memo[j] = pre + s2[j - 1];
        } else if (memo[j - 1].size() > memo[j].size()) {
          memo[j] = memo[j - 1];
        }
        pre = tmp;
      }
    }
    return memo[s2.size()].empty() ? "-1": memo[s2.size()];
  }
};