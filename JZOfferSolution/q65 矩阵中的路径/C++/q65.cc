class Solution {
public:
  static void findPath(char *matrix,
                int rows, int cols, int x, int y,
                char *str, vector<bool> &visited, bool &pathExist) {
    visited[x * cols + y] = true;
    // Match all
    if (*str == '\0') {
      pathExist = true;
      return;
    }
    // Not match
    if (*str != *(matrix + x * cols + y)) {
      visited[x * cols + y] = false;
      return;
    }
    if (*(str + 1) == '\0') {
      pathExist = true;
      return;
    }
    // UP
    if (x - 1 >= 0 && visited[(x - 1) * cols + y] == false) {
      findPath(matrix, rows, cols, x - 1, y, str + 1, visited, pathExist);
    }
    // Down
    if (x + 1 < rows && visited[(x + 1) * cols + y] == false) {
      findPath(matrix, rows, cols, x + 1, y, str + 1, visited, pathExist);
    }
    // Left
    if (y - 1 >= 0 && visited[x * cols + y - 1] == false) {
      findPath(matrix, rows, cols, x, y - 1, str + 1, visited, pathExist);
    }
    // Right
    if (y + 1 < cols && visited[x * cols + y + 1] == false) {
      findPath(matrix, rows, cols, x, y + 1, str + 1, visited, pathExist);
    }
    visited[x * cols + y] = false;
    return;
  }

  static bool hasPath(char *matrix, int rows, int cols, char *str)
  {
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
      return false;
    vector<bool> visited(rows * cols, false);
    bool pathExist = false;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        findPath(matrix, rows, cols, i, j, str, visited, pathExist);
      }
    }
    return pathExist;
  }
};