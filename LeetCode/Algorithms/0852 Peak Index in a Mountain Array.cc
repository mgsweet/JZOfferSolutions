class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l < r) {
            mid = (l + r) / 2;
            if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};