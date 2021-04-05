class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, 1));
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == s[i + 1]) {
                memo[i][i + 1] = 2;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                if (s[i] == s[i + len - 1]) {
                    memo[i][i + len - 1] = memo[i + 1][i + len - 2] + 2;
                } else {
                    memo[i][i + len - 1] = max(memo[i][i + len - 2], memo[i + 1][i + len - 1]);
                }
            }
        }
        return memo[0][n - 1];
    }
};