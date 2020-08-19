class Solution {
public:
  bool static isValidSudoku(vector<vector<char>>& board) {
    array<bool, 10> is_visited;
    // Check Rows
    for (int i = 0; i < 9; ++i) {
      is_visited.fill(false);
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') continue;
        int digit = board[i][j] - '0';
        if (is_visited[digit] == true)
          return false;
        else
          is_visited[digit] = true;
      }
    }
    // Check Cols
    for (int i = 0; i < 9; ++i) {
      is_visited.fill(false);
      for (int j = 0; j < 9; ++j) {
        if (board[j][i] == '.') continue;
        int digit = board[j][i] - '0';
        if (is_visited[digit] == true)
          return false;
        else
          is_visited[digit] = true;
      }
    }
    // Check 9 * 9
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        is_visited.fill(false);
        for (int m = 0; m < 3; ++m) {
          for (int n = 0; n < 3; ++n) {
            if (board[i + m][j + n] == '.') continue;
            int digit = board[i + m][j + n] - '0';
            if (is_visited[digit] == true)
              return false;
            else
              is_visited[digit] = true;
          }
        }
      }
    }
    return true;
  }
};