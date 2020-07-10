class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        // Check if the result is positive
        bool is_positive = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            is_positive = false;
        }
        // set both of it to nagative number
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        int res = 0;
        while (dividend < 0) {
            dividend -= divisor;
            if (dividend <= 0) ++res;
        }
        return is_positive ? res : -res;
    }
};