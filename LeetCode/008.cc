class Solution {
public:
  static int myAtoi(string str) {
    int sign = 1;
    int i = 0;
    if (str.empty()) {
      return 0;
    }
    while (str[i] == ' ') {
      ++i;
    }
    if (str[i] == '+' || str[i] == '-') {
      if (str[i] == '-')
        sign = -1;
      ++i;
    }
    int ans = 0;
    int digit;
    while (i < str.size()) {
      if (str[i] < '0' || str[i] > '9')
        return ans;
      digit = str[i] - '0';
      if (sign == -1 && ans < INT_MIN / 10 || (ans == INT_MIN / 10 && ans * 10 <= INT_MIN + digit)) {
        return INT_MIN;
      } else if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && ans * 10 >= INT_MAX - digit)) {
        return INT_MAX;
      }
      ans = ans * 10 + sign * digit;
      ++i;
    }
    return ans;
  }
};