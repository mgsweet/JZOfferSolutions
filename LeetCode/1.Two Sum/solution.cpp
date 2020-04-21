class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myHashMap;
        int rest;
        unordered_map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++) {
            rest = target - nums[i];
            iter = myHashMap.find(rest);
            if (iter != myHashMap.end()){
                return vector<int>({iter->second, i});
            } else {
                myHashMap[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};
