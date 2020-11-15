class Solution {
public:
  static int bitwiseComplement(int num) {
    if (num == 0) return 1;
    unsigned int mask = ~0;
    while (mask & num) mask <<= 1;
    return ~mask ^ num;
  }
};
