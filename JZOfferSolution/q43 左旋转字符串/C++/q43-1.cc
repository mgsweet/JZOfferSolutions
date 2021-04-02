class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) return str;
        n %= str.size();
        for (int i = 0, j = n - 1; i < j; ++i, --j) 
            swap(str[i], str[j]);
        for (int i = n, j = str.size() - 1; i < j; ++i, --j) 
            swap(str[i], str[j]);
        for (int i = 0, j = str.size() - 1; i < j; ++i, --j)
            swap(str[i], str[j]);
        return str;
    }
};