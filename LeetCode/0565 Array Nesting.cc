class Solution {
private:
  int static EvaluateSize(vector<int> &nums, vector<bool> &is_visited, vector<int> &s_sizes, int pos) {
    if (is_visited[pos]) return s_sizes[pos];
    is_visited[pos] = true;
    s_sizes[pos] = EvaluateSize(nums, is_visited, s_sizes, nums[pos]) + 1;
    return s_sizes[pos];
  }

public:
  int static arrayNesting(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<bool> is_visited(nums.size(), false);
    vector<int> s_sizes(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      if (!is_visited[i]) {
        is_visited[i] = true;
        s_sizes[i] = EvaluateSize(nums, is_visited, s_sizes, nums[i]) + 1;
      }
    }
    return *max_element(s_sizes.begin(), s_sizes.end());
  }
};