class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> my_hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (my_hash.find(nums[i]) != my_hash.end() 
                && i - my_hash[nums[i]] <= k) {
                return true;
            }
            my_hash[nums[i]] = i; 
        }
        return false;
    }
};