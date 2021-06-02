class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> record;
        int res;
        for (auto num: nums) {
            res += record[num];
            ++record[num];
        }
        return res;
    }
};