class Solution {
public:
  string reverseVowels(string s) {
    int lhs = 0;
    int rhs = s.size() - 1;
    set<char> check_set;
    for (char c: "aeiouAEIOU") {
      check_set.insert(c);
    }
    while (lhs < rhs) {
      while (lhs < rhs && check_set.find(s[lhs]) == check_set.end()) {
        ++lhs;
      }
      while (lhs < rhs && check_set.find(s[rhs]) == check_set.end()) {
        --rhs;
      }
      swap(s[lhs++], s[rhs--]);
    }
    return s;
  }
};