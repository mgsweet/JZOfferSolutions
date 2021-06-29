class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n + 1, 0);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                memo[i] += memo[i - 1 - j] * memo[j];
            } 
        }
        return memo[n];
    }
};