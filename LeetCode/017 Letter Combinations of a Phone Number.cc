class Solution {
private:
  const string kDigit[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  int Char2digit(char c) {
    return static_cast<int>(c) - 48 - 2;
  }
public:
  vector<string> letterCombinations(string digits) {
    typedef pair<string, int> Data;
    vector<string> res;
    if (digits.empty()) return res;
    stack<Data> dfs;
    for (char c: kDigit[Char2digit(digits[0])]) {
      dfs.push(Data(string(1, c), 0));
    }
    Data top;
    while (!dfs.empty()) {
      top = dfs.top();
      dfs.pop();
      if (top.second != digits.size() - 1) {
        for (char c: kDigit[Char2digit(digits[top.second + 1])]) {
          dfs.push(Data(top.first + c, top.second + 1));
        }
      } else {
        res.push_back(top.first);
      }
    }
    return res;
  }
};