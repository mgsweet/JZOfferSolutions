class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int digits = 0;
        int tmp = x;
        while (tmp) {
            tmp /= 10;
            ++digits;
        }
        int i = 0, j = digits - 1;
        while(i < j) {
            if (x / static_cast<int>(pow(10, i)) % 10 !=
                x / static_cast<int>(pow(10, j)) % 10) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
