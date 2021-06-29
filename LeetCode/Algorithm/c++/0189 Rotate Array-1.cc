class Solution {
public:
  void static rotate(vector<int>& nums, int k) {
    if (nums.empty() || k < 1) return;
    k %= nums.size();
    if (k == 0) return;
    int next, count = 0;
    for (int i = 0; count < nums.size(); i++) {
      next = (i + k) % nums.size();
      count++;
      while (next != i) {
        count++;
        swap(nums[i], nums[next]);
        next = (next + k) % nums.size();
      }
    }
  }
};