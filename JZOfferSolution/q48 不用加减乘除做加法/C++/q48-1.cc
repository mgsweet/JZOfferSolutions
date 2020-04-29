class Solution {
public:
    int Add(int num1, int num2) {
        int mask = 1;
        int tmp1, tmp2;
        int carry = 0;
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            tmp1 = num1 & mask;
            tmp2 = num2 & mask;
            ans = ans | (tmp1 ^ tmp2 ^ carry);
            carry = ((tmp1 & tmp2) | ((tmp1 | tmp2) & carry)) << 1;
            mask = mask << 1;
        }
        return ans;
    }
};
