class Solution {
public:
  static int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    vector<int> diff;
    for (int i = 1; i < nums.size(); ++i) {
      diff.push_back(nums[i] - nums[i - 1]);
    }
    int pre = -diff[0];
    int count = 1;
    for (int i = 0; i < diff.size(); ++i) {
      if ((diff[i] > 0 && pre < 0) || (diff[i] < 0 && pre > 0)) {
        ++count;
        pre = diff[i];
      } else if (pre == 0 && diff[i] != 0) {
        count = 2;
        pre = diff[i];
      }
    }
    return count;
  }
};