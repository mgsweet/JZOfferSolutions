class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> is_visited(nums.size() + 1, false);
        for (int num : nums) {
            is_visited[num] = true;
        }
        for (int i = 0; i < nums.size() + 1; ++i) {
            if (!is_visited[i]) return i;
        }
        return -1;
    }
};