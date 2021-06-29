class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.empty()) return true;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        return assist(nums, dp, 0, nums.size() - 1) >= 0;
    }
    
    int assist(vector<int> &nums, vector<vector<int>> &dp, int lhs, int rhs){
        if (lhs == rhs) return nums[lhs];
        if (dp[lhs][rhs] > 0) return dp[lhs][rhs];
        dp[lhs][rhs] = max(nums[lhs] - assist(nums, dp, lhs + 1, rhs), nums[rhs] - assist(nums, dp, lhs, rhs - 1));
        return dp[lhs][rhs];
    }
};