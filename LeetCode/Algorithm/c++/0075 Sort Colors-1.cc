class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int, 3> count;
        count.fill(0);
        for (int num: nums) {
            count[num]++;
        }
        int i = 0;
        while (count[0]--) {
            nums[i++] = 0;
        }
        while (count[1]--) {
            nums[i++] = 1;
        }
        while (count[2]--) {
            nums[i++] = 2;
        }
    }
};