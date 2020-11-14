class Solution {
public:
  string toGoatLatin(string str) {
    string res = "";
    string vowel = "aeiouAEIOU";
    int word_count = 0;
    int is_space_now = true;
    int start_with_vowel = false;
    char end_char;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == ' ') {
        if (!is_space_now) {
          if (!start_with_vowel) {
            res += end_char;
          }
          res += "ma";
          res += string(word_count, 'a');
        }
        res += ' ';
        is_space_now = true;
        continue;
      } else {
        if (is_space_now) {
          is_space_now = false;
          ++word_count;
          if (vowel.find(str[i]) != string::npos) {
            start_with_vowel = true;
            res += str[i];
          } else {
            start_with_vowel = false;
            end_char = str[i];
          }
        } else {
          res += str[i];
        }
      }
    }
    if (!is_space_now) {
      if (!start_with_vowel) {
        res += end_char;
      }
      res += "ma";
      res += string(word_count, 'a');
    }
    return res;
  }
};