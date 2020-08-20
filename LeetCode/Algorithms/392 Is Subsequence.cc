class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i_s = 0;
        int i_t = 0;
        while (i_s < s.size() && i_t < t.size()) {
            if (s[i_s] == t[i_t]) {
                ++i_s;
            }
            ++i_t;
        }
        return i_s == s.size();
    }
};