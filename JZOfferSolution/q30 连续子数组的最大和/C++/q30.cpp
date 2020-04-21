
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) exit(EXIT_FAILURE);
        
        int maxSum = array[0];
        int preMax = array[0];
        
        for (int i = 1; i < array.size(); i++) {
            if (preMax > 0) {
                preMax += array[i];
            } else {
                preMax = array[i];
            }
            if (preMax > maxSum) maxSum = preMax;
        }
        
        return maxSum;
    }
};
