class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int>> res;
    if (num.size() < 3) return res;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size() - 2; ++i) {
      if (i > 0 && num[i] == num[i - 1]) continue;
      int lhs = i + 1, rhs = num.size() - 1;
      while (lhs < rhs) {
        int sum = num[lhs] + num[rhs] + num[i];
          if (sum < 0) {
            ++lhs;
          } else if (sum > 0) {
            --rhs;
          } else {
            res.push_back(vector<int>{num[i], num[lhs++], num[rhs--]});
            while(lhs < rhs && num[lhs] == num[lhs - 1]) ++lhs;
            while(lhs < rhs && num[rhs] == num[rhs + 1]) --rhs;
          }
      }
    }
    return res;
  }
};