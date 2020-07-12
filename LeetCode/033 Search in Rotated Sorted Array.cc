class Solution {
public:
  int static search(vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] > nums[left]) {
        // mid in the left sorted array, nums[left to mid] is sorted
        if (target < nums[mid] && target >= nums[left]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] < nums[left]) {
        // mid in the right sorted array, nums[mid to right] is sorted
        if (target > nums[mid] && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        ++left;
      }
    }
    return -1;
  }
};