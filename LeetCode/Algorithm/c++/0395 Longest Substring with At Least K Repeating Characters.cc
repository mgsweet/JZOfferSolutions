class Solution {
private:
  static int assist(string& s, int k, int lhs, int rhs) {
    if (rhs - lhs + 1 < k) return 0;
    if (lhs > rhs) return 0;
    array<int, 26> count;
    count.fill(0);
    for (int i = lhs; i <= rhs; ++i) {
      ++count[s[i] - 'a'];
    }
    int i = lhs;
    while (i <= rhs) {
      if (count[s[i] - 'a'] < k) {
        return max(assist(s, k, lhs, i - 1), assist(s, k, i + 1, rhs));
      };
      ++i;
    }
    return rhs - lhs + 1;
  }
public:
  static int longestSubstring(string s, int k) {
    if (s.empty()) return 0;
    return assist(s, k, 0, s.size() - 1);
  }
};