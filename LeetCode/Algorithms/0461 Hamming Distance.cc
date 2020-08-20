class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        x ^= y;
        while (x) {
            if (x & 1) ++count;
            x >>= 1;
        }
        return count;
    }
};