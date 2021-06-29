class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, 0);
        memo[target] = 1;
        for (int i = target; i > 0; --i) {
            if (memo[i] > 0) {
                for (int j = 0; j <  nums.size(); ++j) {
                    if (i-nums[j] >= 0) {
                        if (memo[i-nums[j]] <= INT_MAX - memo[i]) {
                            memo[i-nums[j]] += memo[i];
                        } else {
                            memo[i-nums[j]] = INT_MAX;
                        }
                    }
                }
            }
        }
        return memo[0];
    }
};