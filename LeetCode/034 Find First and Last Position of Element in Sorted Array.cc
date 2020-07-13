class Solution {
public:
  vector<int> static searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    if (nums.empty()) return ans;
    int left = 0, right = nums.size() - 1;
    // find left
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
        ans[0] = mid;
        break;
      }
      if (nums[mid] >= target) {
        right = mid - 1;
      }
      if (nums[mid] < target) {
        left = mid + 1;
      }
    }
    if (nums[left] == target) ans[0] = left;
    if (ans[0] == -1) return ans;
    // find right
    left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] != target)) {
        ans[1] = mid;
        break;
      }
      if (nums[mid] > target) {
        right = mid - 1;
      }
      if (nums[mid] <= target) {
        left = mid + 1;
      }
    }
    if (nums[right] == target)
      ans[1] = right;
    return ans;
  }
};