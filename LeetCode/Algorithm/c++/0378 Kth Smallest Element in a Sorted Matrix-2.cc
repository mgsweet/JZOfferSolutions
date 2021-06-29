class Solution {
public:
  static int kthSmallest(vector<vector<int>> &matrix, int k) {
    typedef pair<int, pair<int, int>> Point;
    auto compare = [](Point c1, Point c2) { return c1.first > c2.first; };
    priority_queue<Point, vector<Point>, decltype(compare)> bfs(compare);
    for (int i = 0; i < matrix.size(); ++i) {
      bfs.push(Point(matrix[i][0], make_pair(i, 0)));
    }
    int res = -1;
    while (!bfs.empty() && k--) {
      res = bfs.top().first;
      if (bfs.top().second.second + 1 < matrix[0].size()) bfs.push(
          make_pair(matrix[bfs.top().second.first][bfs.top().second.second + 1],
          make_pair(bfs.top().second.first, bfs.top().second.second + 1)));
      bfs.pop();
    }
    return res;
  }
};