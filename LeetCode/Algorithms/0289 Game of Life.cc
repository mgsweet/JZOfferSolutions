class Solution {
private:
  static void addOne(vector<vector<int>> &matrix, int x, int y) {
    for (int i = -1; i < 2; ++i) {
      if (x + i < 0 || x + i >= matrix.size()) continue;
      for (int j = -1; j < 2; ++j) {
        if (y + j < 0 || y + j >= matrix[0].size()) continue;
        ++matrix[x + i][y + j];
      }
    }
  }
public:
  static void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> check(board.size(), vector<int>(board[0].size(), 0));
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j]) addOne(check, i, j);
      }
    }
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (!board[i][j] && check[i][j] == 3) board[i][j] = 1;
        else if (board[i][j] && (check[i][j] < 3 || check[i][j] > 4)) board[i][j] = 0;
      }
    }
  }
};