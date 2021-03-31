class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        vector<vector<int>> memo(str1.size(), vector<int>(str2.size(), 0));
        int max_len = 0;
        int end = -1;
        for (int i = 0; i < str1.size(); ++i) {
            for (int j = 0; j < str2.size(); ++j) {
                if (str2[j] == str1[i]) {
                    if (i == 0 || j == 0) memo[i][j] = 1;
                    else memo[i][j] = memo[i - 1][j - 1] + 1;
                    if (memo[i][j] > max_len) {
                        max_len = memo[i][j];
                        end = j;
                    }
                }
            }
        }
        if (max_len == 0) return "";
        else return str2.substr(end - max_len + 1, max_len);
    }
};