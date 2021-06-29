class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                return i - 1;
        }
        return nums.size() - 1;
    }
};