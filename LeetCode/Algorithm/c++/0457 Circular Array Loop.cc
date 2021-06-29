class Solution {
public:
  static bool circularArrayLoop(vector<int>& nums) {
    vector<int> visit(nums.size(), -1);
    int seq_num = 0, next = 0, index = 0;
    int n = nums.size();
    bool is_positive = false;
    for (int i = 0; i < nums.size(); ++i) {
      if (visit[i] != -1) continue;
      visit[i] = seq_num;
      if (nums[i] != 0) {
        is_positive = nums[i] > 0;
        index = i;
        while (true) {
          next = ((index + nums[index]) % n + n) % n;
          if (next == index) break;
          if ((is_positive && nums[next] < 0) || (!is_positive && nums[next] > 0))
            break;
          if (visit[next] != -1) {
            if (visit[next] < seq_num) break;
            if (visit[next] == seq_num) return true;
          }
          visit[next] = seq_num;
          index = next;
        }
      }
      ++seq_num;
    }
    return false;
  }
};