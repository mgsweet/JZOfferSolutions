class Solution {
public:
  static bool isPerfectSquare(int num) {
    int lhs = 0, rhs = 46340;
    int mid, check;
    if (num > rhs * rhs) return false;
    while (lhs <= rhs) {
      mid = (lhs + rhs) / 2;
      check = mid * mid;
      if (check == num) {
        return true;
      } else if (check > num) {
        rhs = mid - 1;
      } else {
        lhs = mid + 1;
      }
    }
    return false;
  }
};