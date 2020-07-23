class Solution {
public:
    int trailingZeroes(int n) {
        if (n <= 0) return 0;
        int zeros_count = 0;
        while (n) {
            n /= 5;
            zeros_count += n;
        }
        return zeros_count;
    }
};