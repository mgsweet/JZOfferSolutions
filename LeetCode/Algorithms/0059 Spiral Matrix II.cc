class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if (n == 0) return matrix;
        int row_min = 0, row_max = n - 1;
        int col_min = 0, col_max = n - 1;
        int num = 1;
        while (row_min <= row_max && col_min <= col_max) {
            for (int i = col_min; i <= col_max; ++i) matrix[row_min][i] = num++;
            if (++row_min > row_max) break;
            for (int i = row_min; i <= row_max; ++i) matrix[i][col_max] = num++;
            if (--col_max < col_min) break;
            for (int i = col_max; i >= col_min; --i) matrix[row_max][i] = num++;
            if (--row_max < row_min) break;
            for (int i = row_max; i >= row_min; --i) matrix[i][col_min] = num++;
            if (++col_min > col_max) break;
        }
        return matrix;
    }
};