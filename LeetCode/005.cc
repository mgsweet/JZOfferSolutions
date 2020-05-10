class Solution {
public:
  static void SetMaxAndAns(string &s, int l, int r, int &max, string &ans) {
    while (l - 1 >= 0 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
      --l;
      ++r;
    }
    if (r - l + 1 > max) {
      max = r - l + 1;
      ans = string(s, l, max);
    }
  }

  static string longestPalindrome(string s) {
    int l, r;
    string ans = "";
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i > 0 && s[i] == s[i - 1]) {
        l = i - 1;
        r = i;
        SetMaxAndAns(s, l, r, max, ans);
      }
      l = r = i;
      SetMaxAndAns(s, l, r, max, ans);
    }
    return ans;
  }
};