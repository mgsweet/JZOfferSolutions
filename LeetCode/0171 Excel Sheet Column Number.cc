class Solution {
public:
  int static titleToNumber(const string &s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      res *= 26;
      res += (s[i] - 64);
    }
    return res;
  }
};