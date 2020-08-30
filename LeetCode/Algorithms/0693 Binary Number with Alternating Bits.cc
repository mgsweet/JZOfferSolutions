class Solution {
public:
  static bool hasAlternatingBits(int n) {
    while (n) {
      if ((n & 1) == (1 & n >> 1)) return false;
      n >>= 1;
    }
    return true;
  }
};