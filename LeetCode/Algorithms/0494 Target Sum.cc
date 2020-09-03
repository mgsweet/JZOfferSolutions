class Solution {
private:
    void assist(vector<int> &nums, int S, int current, int index, int& count) {
        if (index == nums.size() - 1) {
            if (current == S) ++count;
            return;
        }
        assist(nums, S, current + nums[index + 1], index + 1, count);
        assist(nums, S, current - nums[index + 1], index + 1, count);
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        int count = 0;
        assist(nums, S, 0, -1, count);
        return count;
    }
};