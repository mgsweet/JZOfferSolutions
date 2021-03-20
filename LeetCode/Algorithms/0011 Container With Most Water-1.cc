class Solution {
public:
  static int maxArea(vector<int>& height) {
    int lhs = 0, ans = 0, rhs = height.size() - 1;
    while (lhs < rhs) {
      ans = max(ans, min(height[lhs], height[rhs]) * (rhs - lhs));
      height[lhs] > height[rhs] ? --rhs : ++lhs;
    }
    return ans;
  }
};