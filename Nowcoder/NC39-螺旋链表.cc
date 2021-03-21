class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int row_min = 0, row_max = matrix.size() - 1;
        int col_min = 0, col_max = matrix[0].size() - 1;
        while (row_min <= row_max && col_min <= col_max) {
            for (int i = col_min; i <= col_max; ++i) res.emplace_back(matrix[row_min][i]);
            if (++row_min > row_max) break;
            for (int i = row_min; i <= row_max; ++i) res.emplace_back(matrix[i][col_max]);
            if (--col_max < col_min) break;
            for (int i = col_max; i >= col_min; --i) res.emplace_back(matrix[row_max][i]);
            if (--row_max < row_min) break;
            for (int i = row_max; i >= row_min; --i) res.emplace_back(matrix[i][col_min]);
            if (++col_min > col_max) break;
        }
        return res;
    }
};