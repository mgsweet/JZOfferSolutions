class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (i == 1) {
                nums[1] = max(nums[0], nums[1]);
                continue;
            }
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        }
        return *(nums.end() - 1);
    }
};