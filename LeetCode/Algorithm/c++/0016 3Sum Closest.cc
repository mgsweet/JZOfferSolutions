class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int res;
    int sum, diff, min_diff = INT_MAX;
    int start, end;
    sort(nums.begin(), nums.end());
    for (int i = 0; i + 2 < nums.size(); ++i) {
      start = i + 1;
      end = nums.size() - 1;
      while (start < end) {
        sum = nums[i] + nums[start] + nums[end];
        diff = abs(sum - target);
        if (diff == 0) {
          return target;
        }
        if (diff < min_diff) {
          min_diff = diff;
          res = sum;
        }
        if (sum < target) ++start;
        else --end;
      }
    }
    return res;
  }
};