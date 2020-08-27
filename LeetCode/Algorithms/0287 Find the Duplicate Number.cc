//// O(N2)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         if (nums.size() < 2) return -1;
//         for (int i = 0; i < nums.size() - 1; ++i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if (nums[j] == nums[i]) return nums[j];
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int fast = nums[0], slow = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};