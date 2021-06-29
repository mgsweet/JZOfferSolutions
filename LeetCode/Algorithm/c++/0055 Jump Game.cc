class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2)
            return true;
        int min_jump = 1;
        for (int i = nums.size() - 2; i >= 1; --i) {
            if (nums[i] < min_jump) {
                ++min_jump;
            } else {
                min_jump = 1;
            }
        }
        return nums[0] >= min_jump;
    }
};