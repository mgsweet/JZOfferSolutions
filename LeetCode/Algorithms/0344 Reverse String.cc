class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        for (int i = 0; i < s.size() / 2; ++i) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};