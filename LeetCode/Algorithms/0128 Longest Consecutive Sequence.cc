class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        unordered_set<int> my_set(nums.begin(), nums.end());
        int ans = 0;
        int pre, next;
        while (!my_set.empty()) {
            pre = next = *my_set.begin();
            my_set.erase(my_set.begin());
            while (my_set.find(--pre) != my_set.end()) my_set.erase(pre);
            while (my_set.find(++next) != my_set.end()) my_set.erase(next);
            ans = max(ans, next - pre - 1);
        }
        return ans;
    }
};