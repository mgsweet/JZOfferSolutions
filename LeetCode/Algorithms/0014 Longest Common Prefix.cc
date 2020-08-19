class Solution {
public:
  static string longestCommonPrefix(vector<string>& strs) {
    int index = 0;
    if (strs.empty() || strs[0].empty()) return "";
    bool no_match = false;
    while (1) {
      char curr = strs[0][index];
      for (int i = 0; i < strs.size(); ++i) {
        if (index == strs[i].size() || strs[i][index] != curr) {
          no_match = true;
          break;
        }
      }
      if (no_match) break;
      index++;
    }
    if (index == 0)
      return "";
    return strs[0].substr(0,index);
  }
};