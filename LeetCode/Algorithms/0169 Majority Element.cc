class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int record = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                record = nums[i];
            }
            count += nums[i] == record ? 1 : -1;
        }
        return record;
    }
};