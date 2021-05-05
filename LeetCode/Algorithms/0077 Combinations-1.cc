class Solution {
public:
    void assist(vector<vector<int>> &res, vector<int> &cur, int n, int k) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for (int i = cur.empty() ? 1 : cur.back() + 1; i <= n; ++i) {
            cur.push_back(i);
            assist(res, cur, n, k);
            cur.pop_back();
        }
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        assist(res, cur, n, k);
        return res;
    }
};