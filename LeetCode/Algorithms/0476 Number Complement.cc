class Solution {
public:
  static int findComplement(int num) {
    unsigned int mask = ~0;
    while (mask & num) mask <<= 1;
    return ~mask ^ num;
  }
};