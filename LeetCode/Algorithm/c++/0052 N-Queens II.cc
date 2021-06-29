class Solution {
public:
    static bool IsValid(vector<int> &test) {
        for (int i = 1; i < test.size(); ++i) {
            if (test[i] == -1) continue;
            for (int j = 1; j <= i; ++j) {
                if (test[i] == test[i - j] + j || test[i] == test[i - j] - j)
                  return false;
            }
        }
        return true;
    }

    static void Try(vector<int> &layout, int start, vector<bool> &is_used, int &res) {
      if (start < layout.size()) {
        for (int i = 0; i < is_used.size(); ++i) {
          if (!is_used[i]) {
            layout[start] = i;
            if (IsValid(layout)) {
              is_used[i] = true;
              Try(layout, start + 1, is_used, res);
              is_used[i] = false;
            }
            layout[start] = -1;
          }
        }
      } else {
        ++res;
      }
    }
    
    int totalNQueens(int n) {
      int res = 0;
      vector<int> layout(n, -1);
      vector<bool> is_used(n, false);
      Try(layout, 0, is_used, res);
      return res;
    } 
};