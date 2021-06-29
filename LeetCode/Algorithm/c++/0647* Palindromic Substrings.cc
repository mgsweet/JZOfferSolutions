class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> memo(s.size(), vector<bool>(s.size(), false));
        int count = s.size();
        for (int i = 0; i < s.size(); ++i) {
            memo[i][i] = true;
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                memo[i][i + 1] = true;
                ++count;
            }
        }
        for (int len = 3; len <= s.size(); ++len) {
            for (int i = 0, j = i + len - 1; j < s.size(); ++i, ++j) {
                if (memo[i + 1][j - 1] && s[i] == s[j]) {
                    memo[i][j] = true;
                    ++count;
                }
            }
        }
        return count;
    }
};