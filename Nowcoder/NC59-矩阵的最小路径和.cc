class Solution {
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    static int minPathSum(vector<vector<int> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int cur = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (j > 0 && i > 0) matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1]);
                else if (j > 0) matrix[i][j] += matrix[i][j - 1];
                else if (i > 0) matrix[i][j] += matrix[i - 1][j];
            }
        }
        return matrix[matrix.size() - 1][matrix[0].size() - 1];
    }
};