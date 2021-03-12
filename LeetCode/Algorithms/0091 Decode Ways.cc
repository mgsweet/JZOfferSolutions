class Solution {
public:
  static int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    if (s.size() == 1) return 1;
    vector<int> memo(s.size(), 0);
    memo[0] = 1;
    if (s[1] == '0') {
      memo[1] = s[0] > '2' ? 0 : 1;
    } else {
      if (s[0] == '1' || (s[0] == '2' && s[1] < '7')) memo[1] = 2;
      else memo[1] = 1;
    }
    for (int i = 2; i < s.size(); ++i) {
      if (s[i] != '0') memo[i] += memo[i - 1];
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) memo[i] += memo[i - 2];
    }
    return memo[s.size() - 1];
  }
};