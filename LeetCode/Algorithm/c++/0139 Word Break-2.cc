class Solution {
public:
  static bool assist(string &s, unordered_set<string> &dict, int end) {
    if (end == 0) return true;
    for (int i = 0; i < end; ++i) {
      if (assist(s, dict, i) && dict.count(s.substr(i, end - i)))
        return true;
    }
    return false;
  }
  static bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return assist(s, dict, s.size());
  }
};