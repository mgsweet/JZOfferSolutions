class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty())
            return -1;
        vector<int> step_count(nums.size(), -1);
        step_count[0] = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > step_count[cur])
                ++cur;
            if (step_count[cur] >= nums.size() - 1)
                return cur;
            step_count[cur + 1] = max(i + nums[i], step_count[cur + 1]);
        }
        return -1;
    }
};