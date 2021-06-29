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

    static vector<string> CreateString(vector<int> &layout) {
        vector<string> res;
        for (auto num: layout) {
            string pre(num, '.');
            string suf(layout.size() - num - 1, '.');
            pre += 'Q' + suf;
            res.push_back(pre);
        }
        return res;
    }

    static void Try(vector<int> &layout, int start, vector<bool> &is_used, vector<vector<string>> &res) {
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
        res.push_back(CreateString(layout));
      }
    }

    static vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> res;
      vector<int> layout(n, -1);
      vector<bool> is_used(n, false);
      Try(layout, 0, is_used, res);
      return res;
    }
};