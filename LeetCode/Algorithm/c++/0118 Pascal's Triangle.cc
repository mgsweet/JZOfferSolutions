class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if (numRows < 1) return res;
        vector<int> tmp;
        for (int i = 0; i < numRows; ++i) {
            tmp.clear();
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    tmp.push_back(1);
                } else {
                    tmp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};