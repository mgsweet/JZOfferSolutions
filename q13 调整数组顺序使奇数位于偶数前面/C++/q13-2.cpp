class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> oddArr;
        vector<int> evenArr;
        
        for (auto num : array) {
            if (num % 2) {
                oddArr.push_back(num);
            } else{
                evenArr.push_back(num);
            }
        }
        
        array = oddArr;
        array.insert(array.end(), evenArr.begin(), evenArr.end());
    }
};
