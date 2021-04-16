class Solution {
public:
    bool static cmp(int l, int r) {
        string ls = to_string(l);
        string rs = to_string(r);
        return ls + rs > rs + ls;
    }
    
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (auto num: nums) {
            if (res == "0") 
                return res;
            res += to_string(num);
        }
        return res;
    }
};
