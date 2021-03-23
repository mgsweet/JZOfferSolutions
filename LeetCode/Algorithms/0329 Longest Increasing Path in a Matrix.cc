class Solution {
public:
    int assist(vector<vector<int>> &matrix, vector<vector<int>> &memo, int x, int y) {
        if (memo[x][y] != -1) return memo[x][y];
        int max_before = 0;
        if (x - 1 >= 0 && matrix[x - 1][y] < matrix[x][y]) 
            max_before = max(max_before, assist(matrix, memo, x - 1, y));
        if (x + 1 < matrix.size() && matrix[x + 1][y] < matrix[x][y]) 
            max_before = max(max_before, assist(matrix, memo, x + 1, y));
        if (y - 1 >= 0 && matrix[x][y - 1] < matrix[x][y]) 
            max_before = max(max_before, assist(matrix, memo, x, y - 1));
        if (y + 1 < matrix[0].size() && matrix[x][y + 1] < matrix[x][y]) 
            max_before = max(max_before, assist(matrix, memo, x, y + 1));
        memo[x][y] = max_before + 1;
        return memo[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));
        int max_incre = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); j++) {
                max_incre = max(max_incre, assist(matrix, memo, i, j));
            }
        }
        return max_incre;
    }
};