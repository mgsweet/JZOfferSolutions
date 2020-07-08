class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        bool one_appear = false;
        while (n) {
            if (n & 1) {
                if (one_appear) return false;
                one_appear = true;
            }
            n = n >> 1;
        }
        return one_appear;
    }
};