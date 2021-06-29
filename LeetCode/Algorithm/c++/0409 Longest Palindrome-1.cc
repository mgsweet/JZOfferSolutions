class Solution {
public:
    static int longestPalindrome(string s) {
        unordered_map<char, bool> check;
        int count = 0;
        for (char &c : s) {
            if (check.find(c) != check.end() && check[c]) {
                count+=2;
                check[c] = false;
            } else {
                check[c] = true;
            }
        }
        for (auto iter = check.begin(); iter != check.end(); ++iter) {
            if (iter->second) {
              ++count;
              break;
            }
        }
        return count;
    }
};