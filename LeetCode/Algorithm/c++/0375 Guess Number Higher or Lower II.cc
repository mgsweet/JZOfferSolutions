class Solution {
public:
    static int getMoneyAmount(int n) {
        int record[205][205];
        return assist(record, 0, n);
    }

    static int assist(int record[][205], int lhs, int rhs) {
      if (lhs >= rhs) {
        return 0;
      } else if (lhs == rhs - 1) {
        return lhs;
      } else {
        if (record[lhs][rhs] != 0) return record[lhs][rhs];
        int min_cost = INT_MAX;
        for (int i = lhs; i <= rhs; ++i) {
          min_cost = min(max(assist(record, lhs, i - 1), assist(record, i + 1, rhs)) + i, min_cost);
        }
        record[lhs][rhs] = min_cost;
      }
      return record[lhs][rhs];
    }
};