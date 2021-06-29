class Solution {
public:
  static int maxProduct(vector<int> &nums) {
    if (nums.empty()) return 0;
    int ans = nums[0];
    int min_pre = nums[0];
    int max_pre = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        min_pre = min(min_pre * nums[i], nums[i]);
        max_pre = max(max_pre * nums[i], nums[i]);
      } else if (nums[i] < 0) {
        int tmp = min_pre;
        min_pre = min(max_pre * nums[i], nums[i]);
        max_pre = max(tmp * nums[i], nums[i]);
      } else {
        min_pre = max_pre = 0;
      }
      ans = max(max_pre, ans);
    }
    return ans;
  }
};