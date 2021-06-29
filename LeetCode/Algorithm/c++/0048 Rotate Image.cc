class Solution {
public:
  static void rotate(vector<vector<int>>& matrix) {
    if (matrix.size() < 2) return;
    int rows = matrix.size() - 1;
    int cols = matrix[0].size() - 1;
    for (int i = 0; i <= rows / 2; ++i) {
      for (int j = i; j < cols - i; ++j) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[rows - j][i];
        matrix[rows - j][i] = matrix[rows - i][cols - j];
        matrix[rows - i][cols - j] = matrix[j][cols - i];
        matrix[j][cols - i] = tmp;
      }
    }
  }
};