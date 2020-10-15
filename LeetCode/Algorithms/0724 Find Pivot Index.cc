class Solution {
public:
  static int pivotIndex(vector<int> &nums) {
    int l_sum = 0, sum = 0;
    for (auto &n: nums) sum += n;
    for (int i = 0; i < nums.size(); ++i) {
      if (l_sum == sum - l_sum - nums[i]) return i;
      l_sum += nums[i];
    }
    return -1;
  }
};