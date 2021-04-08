class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        if (A.empty() || n <= 0 || A.size() != n)
            return 0;
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        int res = 1;
        for (int i = 0; i < n; ++i) {
            memo[i][i] = true;
            if (i + 1 < n && A[i] == A[i + 1]){
                res = 2;
                memo[i][i + 1] = true;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                if (A[i] == A[i + len - 1] && memo[i + 1][i + len - 2]) {
                    res = len;
                    memo[i][i + len - 1] = true;
                }
            }
        }
        return res;
    }
};