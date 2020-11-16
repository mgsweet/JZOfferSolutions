class Solution {
public:
  static int bitwiseComplement(int N) {
    int c = 1;
    while (c < N) c = c << 1 | 1;
    return c ^ N;
  }
};