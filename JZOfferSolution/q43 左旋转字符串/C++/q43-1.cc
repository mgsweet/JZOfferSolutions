class Solution {
public:
    void swap_char(char &a, char &b) {
        char tmp = a;
        a = b;
        b = tmp;
    }
    
    string LeftRotateString(string str, int n) {
        if (n <= 0 || str.empty()) return str;
        n %= str.size();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            swap_char(str[i], str[j]);
        }
        for (int i = n, j = str.size() - 1; i < j; ++i, --j) {
            swap_char(str[i], str[j]);
        }
        for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
            swap_char(str[i], str[j]);
        }
        return str;
    }
};
