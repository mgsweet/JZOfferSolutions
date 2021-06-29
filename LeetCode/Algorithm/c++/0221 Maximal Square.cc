class Solution {
public:
  static int findMin(int v1, int v2, int v3) {
    int res = min(v1, v2);
    res = min(res, v3);
    return res;
  }

  static int maximalSquare(vector<vector<char>> &matrix) {
    vector<vector<int>> int_matrix;
    if (matrix.size() == 0) return 0;
    int res = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      int_matrix.push_back(vector<int>());
      for (int j = 0; j < matrix[0].size(); ++j) {
        int_matrix[i].push_back((int) matrix[i][j] - '0');
        if (i > 0 && j > 0 && int_matrix[i][j] > 0) {
          int_matrix[i][j] = find_min(int_matrix[i - 1][j - 1],
                                      int_matrix[i][j - 1],
                                      int_matrix[i - 1][j]) + 1;
        }
        res = max(int_matrix[i][j], res);
      }
    }
    return res * res;
  }
};