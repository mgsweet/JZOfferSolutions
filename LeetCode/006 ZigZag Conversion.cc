class Solution {
public:
  static string convert(string s, int numRows) {
    string ans;
    if (numRows < 1) return ans;
    if (numRows == 1) return s;
    for (int i = 0; i < numRows; ++i) {
      int j = i;
      int next1 = (numRows - 1 - i) * 2;
      int next2 = i * 2;
      int next = next1;
      while (j < s.size()) {
        if (next != 0) {
          ans.push_back(s[j]);
          j += next;
        }
        next = next == next1 ? next2 : next1;
      }
    }
    return ans;
  }
};