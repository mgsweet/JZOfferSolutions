class Solution {
private:
    void HelpGenerate(string & current, int l_left, int r_left, vector<string> & ans) {
        if (l_left == 0 && r_left == 0) ans.push_back(current);
        if (l_left > 0) {
            current.push_back('(');
            HelpGenerate(current, l_left - 1, r_left + 1, ans);
            current.pop_back();
        }
        if (r_left > 0) {
            current.push_back(')');
            HelpGenerate(current, l_left, r_left - 1, ans);
            current.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n <= 0) return ans;
        string current;
        HelpGenerate(current, n, 0, ans);
        return ans;
    }
};