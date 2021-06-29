class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int i2, i3, sum;
    for (int i1 = 0; i1 + 2 < nums.size(); ++i1) {
      if (nums[i1] > 0) break;
      if (i1 > 0 && nums[i1] == nums[i1 - 1]) continue;
      i2 = i1 + 1;
      i3 = nums.size() - 1;
      while (i2 < i3) {
        sum = nums[i1] + nums[i2] + nums[i3];
        if (sum == 0) {
          res.push_back({nums[i1], nums[i2], nums[i3]});
          // Skip duplicated
          while (i2 + 1 < i3 && nums[i2 + 1] == nums[i2]) ++i2;
          while (i3 - 1 > i2 && nums[i3 - 1] == nums[i3]) --i3;
          ++i2;
          --i3;
        } else if (sum > 0) {
          --i3;
        } else {
          ++i2;
        }
      }
    }
    return res;
  }
};