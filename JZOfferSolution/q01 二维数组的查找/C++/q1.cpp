class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty() || array[0].empty()) return false;
        int i = 0;
        int j = array[0].size() - 1;
        while (i < array.size() && j >= 0) {
            if (target == array[i][j])
                return true;
            if (array[i][j] > target)
                j--;
            else if (array[i][j] < target)
                i++;
        } 
        return false;
    }
};
