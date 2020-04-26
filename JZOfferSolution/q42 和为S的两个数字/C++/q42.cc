class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if (array.size() < 2) {
            return result;
        }
        int small = 0;
        int big = array.size() - 1;
        while (small < big) {
            int curSum = array[small] + array[big];
            if (curSum == sum) {
                result.push_back(array[small]);
                result.push_back(array[big]);
                return result;
            } else if (curSum > sum) {
                big--;
            } else {
                small++;
            }
        }
        return result;
    }
};
