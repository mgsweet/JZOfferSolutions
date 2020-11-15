class Solution {
public:
  static int bitwiseComplement(int N) {
    int count = 0, temp = N;
    while (temp >>= 1) {
      ++count;
    }
    unsigned int mask = 1;
    mask <<= (count + 1);
    return N ^ (mask - 1);
  }
};