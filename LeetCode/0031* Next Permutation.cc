class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            --i;
        }
        if (i > 0) {
            int j = nums.size() -1;
            while (j >= 0 && nums[j] <= nums[i - 1]) {
                --j;
            }
            swap(nums[i - 1], nums[j]);
        }
        reverse(nums.begin() + i, nums.end());
        return;
    }
};