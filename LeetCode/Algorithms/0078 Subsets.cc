class Solution {
void Assist(vector<vector<int>> &ans, vector<int> &nums, vector<int> &current_set, int current_index) {
    if (current_index == nums.size()) {
        ans.push_back(current_set);
        return;
    }
    current_set.push_back(nums[current_index]);
    Assist(ans, nums, current_set, current_index + 1);
    current_set.pop_back();
    Assist(ans, nums, current_set, current_index + 1);
}    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current_set;
        Assist(ans, nums, current_set, 0);
        return ans;
    }
};