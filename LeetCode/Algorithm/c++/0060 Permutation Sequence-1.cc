class Solution {
public:
  static string getPermutation(int n, int k) {
    int mul = 1;
    for (int i = 1; i < n; ++i) {
      mul *= i;
    }
    vector<int> is_visited(n, false);
    string res;
    for (int i = n - 1; i > 0; --i) {
      int index = (k - 1) / mul;
      int count = -1;
      int j = -1;
      while (count != index && j < n) {
        if (is_visited[++j]) continue;
        ++count;
      }
      res += to_string(j + 1);
      is_visited[j] = true;
      k -= index * mul;
      mul /= i;
    }
    for (int i = 0; i < n; ++i) {
      if (!is_visited[i]) {
        res += to_string(i + 1);
        break;
      }
    }
    return res;
  }
};