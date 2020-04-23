class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    array<int, 128> arr;
    arr.fill(-1);
    int max_len = 0;
    int current_len, char_code;
    for (int i = 0, j = 0; j < s.size(); j++) {
      char_code = static_cast<int>(s[j]);
      if (arr[char_code] != -1) {
        i = max(i, 1 + arr[char_code]);
      }
      current_len = j - i + 1;
      max_len = max(max_len, current_len);
      arr[char_code] = j;
    }
    return max_len;
  }
};
