class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, r1 = 0, r2 = 0;
        for (auto num : nums) {
            if (num == c1) {
                ++r1;
            } else if (num == c2) {
                ++r2;
            } else if (r1 == 0) {
                c1 = num;
                r1 = 1;
            } else if (r2 == 0) {
                c2 = num;
                r2 = 1;
            } else {
                --r1;
                --r2;
            }
        }
        r1 = r2 = 0;
        for (auto num : nums) {
            if (num == c1) ++r1;
            if (num == c2) ++r2;
        }
        vector<int> res;
        if (r1 > nums.size() / 3) res.emplace_back(c1);
        if (c1 != c2 && r2 > nums.size() / 3) res.emplace_back(c2);
        return res;
    }
};