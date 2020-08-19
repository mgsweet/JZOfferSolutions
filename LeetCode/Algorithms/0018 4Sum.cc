class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());
    int i1, i2, i3, i4;
    int sub_target, diff;
    for (i1 = 0; i1 + 3 < nums.size(); ++i1) {
      if (i1 > 0 && nums[i1] == nums[i1 - 1]) continue;
      for (i2 = i1 + 1; i2 + 2 < nums.size(); ++i2) {
        if (i2 > i1 + 1 && nums[i2] == nums[i2 - 1]) continue;
        i3 = i2 + 1;
        i4 = nums.size() - 1;
        sub_target = target - nums[i1] - nums[i2];
        while (i3 < i4) {
          diff = sub_target - nums[i3] - nums[i4];
          if (diff == 0) {
            res.push_back(vector<int>({nums[i1], nums[i2], nums[i3], nums[i4]}));
            while (i3 + 1 < i4 && nums[i3 + 1] == nums[i3]) ++i3;
            while (i3 < i4 - 1 && nums[i4 - 1] == nums[i4]) --i4;
            ++i3;
            --i4;
          } else if (diff > 0) {
            while (i3 + 1 < i4 && nums[i3 + 1] == nums[i3]) ++i3;
            ++i3;
          } else {
            while (i3 < i4 - 1 && nums[i4 - 1] == nums[i4]) --i4;
            --i4;
          }
        }
      }
    }
    return res;
  }
};