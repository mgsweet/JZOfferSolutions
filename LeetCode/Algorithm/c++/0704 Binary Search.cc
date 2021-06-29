class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int start = 0, end = nums.size() - 1;
        int mid;
        while (start < end) {
            mid = start / 2 + end / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        if (start == end && nums[start] == target) return start; 
        return -1;
    }
};