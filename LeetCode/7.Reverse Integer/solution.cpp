
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int x_mod = 0;
        while (x != 0) {
            x_mod = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10
                || (rev == INT_MAX / 10 && x_mod > 7))
                return 0;
            if (rev < INT_MIN / 10
                || (rev == INT_MIN / 10 && x_mod < -8))
                return 0;
            rev = rev * 10 + x_mod;
        }
        return rev;
    }
};
