class Solution {
private:
  static int AssistStr2int(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      return tolower(c);
    }
    if (c >= '0' && c <= '9') return c;
    return -1;
  }

public:
  static bool isPalindrome(string s) {
    if (s.empty()) return true;
    int lhs = 0, rhs = s.size() - 1;
    int l_v, r_v;
    while (rhs > lhs) {
      l_v = AssistStr2int(s[lhs]);
      while (l_v == -1 && rhs > lhs) {
        ++lhs;
        l_v = AssistStr2int(s[lhs]);
      }
      r_v = AssistStr2int(s[rhs]);
      while (r_v == -1 && rhs > lhs) {
        --rhs;
        r_v = AssistStr2int(s[rhs]);
      }
      if (l_v != r_v) return false;
      ++lhs;
      --rhs;
    }
    return true;
  }
};