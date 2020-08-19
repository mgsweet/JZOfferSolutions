class Solution {
private:
    void GetPermute(vector<int> &nums, vector<bool> &is_visited, vector<int> &permutation, vector<vector<int>> &ans) {
        if (permutation.size() == nums.size()) ans.push_back(permutation);
        for (int i = 0; i < nums.size(); ++i) {
            if (!is_visited[i]) {
                is_visited[i] = true;
                permutation.push_back(nums[i]);
                GetPermute(nums, is_visited, permutation, ans);
                permutation.pop_back();
                is_visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        vector<bool> is_visited(nums.size(), false);
        vector<int> permutation;
        GetPermute(nums, is_visited, permutation, ans);
        return ans;
    }
};