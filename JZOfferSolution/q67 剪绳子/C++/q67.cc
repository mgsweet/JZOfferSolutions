class Solution {
public:
  static int cutRope(int number) {
    if (number < 2) return 0;
    if (number < 4) return number - 1;
    int ans = 1;
    while (number > 4) {
      ans *= 3;
      number -= 3;
    }
    ans *= number;
    return ans;
  }
};