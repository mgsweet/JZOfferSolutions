class Solution {
public:
    char findTheDifference(string s, string t) {
        array<int, 26> a;
        a.fill(0);
        for (char &c : s) {
            ++a[c - 'a'];
        }
        for (char &c : t) {
            --a[c - 'a'];
            if (a[c - 'a'] < 0) return c;
        }
        return '0';
    }
};