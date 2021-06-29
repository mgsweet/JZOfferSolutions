class Solution {
public:
  static int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int count = nums[1] == nums[0] ? 1 : 2;
    int pre_diff = nums[1] - nums[0];
    int diff;
    for (int i = 2; i < nums.size(); ++i) {
      diff = nums[i] - nums[i - 1];
      if ((diff > 0 && pre_diff <= 0) || (diff < 0 && pre_diff >= 0)) {
        ++count;
        pre_diff = diff;
      }
    }
    return count;
  }
};