class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> nums) {
        if (nums.empty()) return 0;
        int cur = nums[0];
        int cur_count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == cur) 
                ++cur_count;
            else
                --cur_count;
            if (cur_count == 0) {
                cur = nums[i];
                cur_count = 1;
            }
        }
        cur_count = 0;
        for (auto num: nums) {
            if (num == cur)
                ++cur_count;
        }
        return cur_count > nums.size() / 2 ? cur : 0;
    }
};