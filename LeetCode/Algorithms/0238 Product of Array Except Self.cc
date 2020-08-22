class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums);
        if (nums.size() < 2) return ans;
        vector<int> pre_product(nums);
        vector<int> suf_product(nums);
        for (int i = 1; i < nums.size(); ++i) {
            pre_product[i] *= pre_product[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            suf_product[i] *= suf_product[i + 1];
        }
        for (int i = 1; i < nums.size() - 1; ++i) {
            ans[i] = pre_product[i - 1] * suf_product[i + 1];
        }
        ans[0] = suf_product[1];
        ans[nums.size() - 1] = pre_product[nums.size() - 2];
        return ans;
    }
};