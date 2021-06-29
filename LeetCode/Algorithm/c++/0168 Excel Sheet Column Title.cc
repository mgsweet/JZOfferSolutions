class Solution {
public:
  string static convertToTitle(int n) {
    string ans;
    if (n < 1) return "ERROR";
    int digit;
    while (n) {
      digit = n % 26;
      if (digit == 0) {
        digit = 26;
        --n;
      }
      ans = char(digit + 64) + ans;
      n /= 26;
    }
    return ans;
  }
};