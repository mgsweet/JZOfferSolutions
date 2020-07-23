class Solution {
public:
  void static rotate(vector<int>& nums, int k) {
    if (nums.empty() || k < 1) return;
    k %= nums.size();
    if (k == 0) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};