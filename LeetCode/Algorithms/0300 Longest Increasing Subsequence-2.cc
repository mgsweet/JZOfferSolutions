class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(memo.begin(), memo.end(), nums[i]);
            if (it == memo.end()) memo.push_back(nums[i]);
            else *it = nums[i];
        }
        return memo.size();
    }
};