class Solution {
public:
  static vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums);
    if (nums.size() < 2) return ans;
    for (int i = 1; i < nums.size(); ++i) {
      ans[i] *= ans[i - 1];
    }
    int R = 1;
    for (int i = nums.size() - 1; i > 0; --i) {
      ans[i] = ans[i - 1] * R;
      R *= nums[i];
    }
    ans[0] = R;
    return ans;
  }
};