class Solution {
public:
  vector<int> static getRow(int rowIndex) {
    if (rowIndex < 0) return vector<int>();
    vector<int> res(rowIndex + 1, 0);
    // tmp and pre are used to record the number in the previous row.
    // Only have to record one number because every new value in the current row
    // only depend on the 2 value in the previous row. One has been replace, the other not.
    // We have to record the previous value of the replace one.
    int tmp, pre;
    for (int i = 0; i <= rowIndex; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j == 0 || j == i) {
          res[j] = 1;
          pre = 1;
        } else {
          tmp = res[j];
          res[j] = pre + res[j];
          pre = tmp;
        }
      }
    }
    return res;
  }
};