class Solution {
public:
  static int maxArea(vector<int>& height) {
    int lhs = 0, ans = 0, rhs = height.size() - 1;
    while (lhs < rhs) {
      int h = min(height[lhs], height[rhs]);
      ans = max(ans, h * (rhs - lhs));
      while(lhs < rhs && height[lhs] <= h) ++lhs;
      while(lhs < rhs && height[rhs] <= h) --rhs;
    }
    return ans;
  }
};