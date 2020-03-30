class Solution {
private:
    vector<int> printCircle(const vector<vector<int> > & matrix,
                           int rowStart, int rowEnd,
                           int colStart, int colEnd) {
        vector<int> currentCircle;
        
        if (rowStart == rowEnd && colStart == colEnd) {
            currentCircle.push_back(matrix[rowStart][colStart]);
        } else if (rowStart == rowEnd && colStart != colEnd) {
            for (int i = colStart; i <= colEnd; i++) {
                currentCircle.push_back(matrix[rowStart][i]);
            }
        } else if (rowStart != rowEnd && colStart == colEnd) {
            for (int i = rowStart; i <= rowEnd; i++) {
                currentCircle.push_back(matrix[i][colEnd]);
            }
        } else {
            for (int i = colStart; i < colEnd; i++) {
                currentCircle.push_back(matrix[rowStart][i]);
            }
            for (int i = rowStart; i < rowEnd; i++) {
                currentCircle.push_back(matrix[i][colEnd]);
            }
            for (int i = colEnd; i > colStart; i--) {
                currentCircle.push_back(matrix[rowEnd][i]);
            }
            for (int i = rowEnd; i > rowStart; i--) {
                currentCircle.push_back(matrix[i][colStart]);
            }
        }
        return currentCircle;
    }
    
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> circleOut;
        if (matrix.empty()) return circleOut;
        
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        
        while (rowStart <= rowEnd && colStart <= colEnd) {
            vector<int> currentCircle = printCircle(matrix, rowStart, rowEnd,
                                                  colStart, colEnd);
            circleOut.insert(circleOut.end(), currentCircle.begin(), currentCircle.end());
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
        return circleOut;
    }
};
