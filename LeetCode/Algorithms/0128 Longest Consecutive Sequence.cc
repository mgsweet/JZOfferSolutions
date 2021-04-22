class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        unordered_set<int> my_set(nums.begin(), nums.end());
        int ans = 0;
        while (!my_set.empty()) {
          int tmp_ans = 1;
          int cur = *my_set.begin();
          int tmp_cur = cur;
          while (my_set.find(--tmp_cur) != my_set.end()) {
            my_set.erase(tmp_cur);
            ++tmp_ans;
          }
          tmp_cur = cur;
          while (my_set.find(++tmp_cur) != my_set.end()) {
            my_set.erase(tmp_cur);
            ++tmp_ans;
          }
          my_set.erase(cur);
          ans = max(ans, tmp_ans);
        }
        return ans;
    }
};