class Solution {
public:
  static int kthSmallest(vector<vector<int>>& matrix, int k) {
    typedef pair<int, int> Point;
    multimap<int, Point> bfs;
    if (matrix.empty()) return -1;
    bfs.insert(make_pair(matrix[0][0], Point(0, 0)));
    int ans = -1;
    vector<vector<bool>> visited;
    int x, y;
    for (auto & v : matrix) {
      visited.push_back(vector<bool>(v.size(), false));
    }
    visited[0][0] = true;
    while (!bfs.empty() && k) {
      ans = bfs.begin()->first;
      --k;
      x = bfs.begin()->second.first;
      y = bfs.begin()->second.second;
      bfs.erase(bfs.begin());
      if (x + 1 < matrix.size()
        && !visited[x + 1][y]) {
        visited[x + 1][y] = true;
        bfs.insert(make_pair(matrix[x + 1][y], Point(x + 1, y)));
      }
      if (y + 1 < matrix[0].size()
        && !visited[x][y + 1]) {
        visited[x][y + 1] = true;
        bfs.insert(make_pair(matrix[x][y + 1], Point(x, y + 1)));
      }
    }
    return ans;
  }
};