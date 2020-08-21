class Solution {
public:
  static bool isPalindrome(string s) {
    if (s.empty()) return true;
    int lhs = 0, rhs = s.size() - 1;
    while (rhs > lhs) {
      while (!isalnum(s[lhs]) && rhs > lhs) ++lhs;
      while (!isalnum(s[rhs]) && rhs > lhs) --rhs;
      if (tolower(s[lhs++]) != tolower(s[rhs--])) return false;
    }
    return true;
  }
};