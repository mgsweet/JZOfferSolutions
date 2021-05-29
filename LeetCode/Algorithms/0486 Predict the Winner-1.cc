class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.empty()) return true;
        return assist(nums, 0, nums.size() - 1) >= 0;
    }
    
    int assist(vector<int> &nums, int lhs, int rhs){
        if (lhs == rhs) return nums[lhs];
        return max(nums[lhs] - assist(nums, lhs + 1, rhs), 
                   nums[rhs] - assist(nums, lhs, rhs - 1));
    }
};