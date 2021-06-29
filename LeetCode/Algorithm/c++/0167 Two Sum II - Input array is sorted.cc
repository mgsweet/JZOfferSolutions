class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lhs = 0;
        int rhs = numbers.size() - 1;
        int sum;
        vector<int> res;
        while (lhs != rhs) {
            sum = numbers[lhs] + numbers[rhs];
            if (sum > target) {
                --rhs;
            } else if (sum < target) {
                ++lhs;
            } else {
                res.push_back(lhs + 1);
                res.push_back(rhs + 1);
                break;
            }
        }
        return res;
    }
};