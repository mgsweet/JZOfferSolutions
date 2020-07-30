class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0;
        int sum = 0;
        while (sum <= n) {
            ++i;
            if (sum > INT_MAX - i) break;
            sum += i;
        }
        return i - 1;
    }
};