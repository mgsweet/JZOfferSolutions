class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int max_length = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    max_length = max(memo[j], max_length);
                }
            }
            memo[i] = max_length + 1;
            res = max(memo[i], res);
        }
        return res;
    }
};