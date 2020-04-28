class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5) return false;
        sort(numbers.begin(), numbers.end());
        int count_zero = 0;
        int pre_num = 0;
        for (const int &num : numbers) {
            if (num == 0) {
                count_zero++;
            } else {
                if (pre_num == 0) {
                    pre_num = num;
                } else if (pre_num == num) {
                    return false;
                } else {
                    count_zero -= (num - pre_num - 1);
                    pre_num = num;
                }
            }
        }
        return count_zero >= 0;
    }
};
