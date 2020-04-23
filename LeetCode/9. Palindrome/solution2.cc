class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        auto i = str.begin(), j = str.end() - 1;
        while (i < j) {
            if (*i++ != *j--) {
                return false;
            }
        }
        return true;
    }
};
