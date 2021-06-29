class Solution {
public:
  static int lengthOfLastWord(string s) {
    if (s.empty()) return 0;
    int count = 0;
    auto iter = s.end() - 1;
    while (iter >= s.begin()) {
      if (*iter != ' ') break;
      --iter;
    }
    while (iter >= s.begin()) {
      if (*iter == ' ') return count;
      ++count;
      --iter;
    }
    return count;
  }
};