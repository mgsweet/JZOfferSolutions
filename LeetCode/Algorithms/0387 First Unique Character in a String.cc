class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> char_appear_times;
    for (char c : s) {
      ++char_appear_times[c];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (char_appear_times[s[i]] == 1)
        return i;
    }
    return -1;
  }
};