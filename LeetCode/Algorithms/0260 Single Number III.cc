class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() < 2) return vector<int> {-1, -1};
        unsigned int tmp = 0;
        for (auto num: nums) {
            tmp ^= num;
        }
        unsigned int seperate = 1;
        while((seperate & tmp) == 0) {
            seperate <<= 1;
        }
        int ans1 = 0, ans2 = 0;
        for (auto num: nums) {
            if (num & seperate) {
                ans1 ^= num;
            } else {
                ans2 ^= num;
            }
        }
        return vector<int>{ans1, ans2};
    }
};