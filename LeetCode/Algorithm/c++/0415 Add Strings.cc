class Solution {
public:
  static string addStrings(string num1, string num2) {
    if (num1.size() < num2.size()) swap(num1, num2);
    int carry = 0, digit1, digit2, sum;
    auto iter1 = num1.rbegin();
    auto iter2 = num2.rbegin();
    while (iter1 != num1.rend() && (iter2 != num2.rend() || carry)) {
      digit2 = iter2 != num2.rend() ? *iter2++ - '0' : 0;
      digit1 = *iter1 - '0';
      sum = digit1 + digit2 + carry;
      *iter1 = (sum % 10) + '0';
      iter1++;
      carry = sum / 10;
    }
    if (carry != 0) {
      num1 = '1' + num1;
    }
    return num1;
  }
};