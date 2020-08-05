class Solution {
public:
    string convertToBase7(int num) {
        bool is_negative = false;
        if (num < 0) {
            num = -num;
            is_negative = true;
        }
        int base = 1;
        while (base * 7 <= num) {
            base *= 7;
        }
        string ans;
        while (base) {
            int digit = num / base;
            num = num % base;
            base /= 7;
            ans += to_string(digit);
        }
        if (is_negative) {
            ans = "-" + ans;
        }
        return ans;
    }
};