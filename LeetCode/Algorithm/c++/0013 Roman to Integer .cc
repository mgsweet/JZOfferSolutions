class Solution {
public:
    int char_to_num(char roman, int high) {
        int ans;
        switch(roman) {
            case 'I':
                ans = 1;
                break;
            case 'V':
                ans = 5;
                break;
            case 'X':
                ans = 10;
                break;
            case 'L':
                ans = 50;
                break;
            case 'C':
                ans = 100;
                break;
            case 'D':
                ans = 500;
                break;
            case 'M':
                ans = 1000;
                break;
            default:
                ans = 0;
                break;
        }
        if (ans < high) ans = -ans;
        return ans;
    }
    int romanToInt(string s) {
        int ans = 0;
        int high = 1;
        int tmp = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            tmp = char_to_num(s[i], high);
            high = high > tmp ? high : tmp;
            ans += tmp;
        }
        return ans;
    }
};
