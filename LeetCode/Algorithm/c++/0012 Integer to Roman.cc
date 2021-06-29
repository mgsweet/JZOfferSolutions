class Solution {
public:
  string intToRoman(int num) {
    string res, tmp;
    const string kSymbol = "IVXLCDM";
    int digit, symbol_pos = 0;
    while (num) {
      tmp = "";
      digit = num % 10;
      num /= 10;
      if (digit == 9) {
        tmp.push_back(kSymbol[symbol_pos]);
        tmp.push_back(kSymbol[symbol_pos + 2]);
        digit -= 9;
      } else if (digit == 4) {
        tmp.push_back(kSymbol[symbol_pos]);
        tmp.push_back(kSymbol[symbol_pos + 1]);
        digit -= 4;
      } else if (digit >= 5) {
        tmp.push_back(kSymbol[symbol_pos + 1]);
        digit -= 5;
      }
      while (digit--) {
        tmp.push_back(kSymbol[symbol_pos]);
      }
      res = tmp + res;
      symbol_pos += 2;
    }
    return res;
  }
};