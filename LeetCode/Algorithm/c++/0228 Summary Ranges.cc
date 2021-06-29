class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = nums[0];
        int end = start;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != end + 1) {
                if (start != end) res.push_back(to_string(start) + "->" + to_string(end));
                else res.push_back(to_string(start));
                start = end = nums[i];
            } else {
                end = nums[i];
            }
        }
        if (start != end) res.push_back(to_string(start) + "->" + to_string(end));
        else res.push_back(to_string(start));
        return res;
    }
};