class Solution {
public:
  static int getSum(int a, int b) {
    unsigned int _a = a, _b = b;
    bool carry = false;
    unsigned int mask = 1;
    unsigned int res = 0;
    while(true) {
      if (carry) {
        res = res | ((_a ^ _b ^ mask) & mask);
        carry = ((_a | _b) & mask) != 0;
      } else {
        res = res | ((_a ^ _b) & mask);
        carry = ((_a & _b) & mask) != 0;
      }
      if (mask == 1 << 31)
        return static_cast<int>(res);
      mask <<= 1;
    }
  }
};