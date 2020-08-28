class Solution {
private:
  int partition(vector<int> &nums, int lhs, int rhs) {
    int baseVal = lhs;
    while (lhs < rhs) {
      while (lhs < rhs && nums[rhs] >= baseVal) --rhs;
      nums[lhs] = nums[rhs];
      while (lhs < rhs && nums[lhs] <= baseVal) ++lhs;
      nums[rhs] = nums[lhs];
    }
    nums[lhs] = baseVal;
    return lhs;
  }

  int reFindKthLargest(vector<int> &nums, int k, int lhs, int rhs) {
    int mid = partition(nums, lhs, rhs);
    if (mid < nums.size() - k) reFindKthLargest(nums, k, mid, rhs);
    else if (mid > nums.size() - k) reFindKthLargest(nums, k, lhs, mid);
    else return nums[mid];
  }

public:
  int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size()) return -1;
    return reFindKthLargest(nums, k, 0, nums.size() - 1);
  }
};