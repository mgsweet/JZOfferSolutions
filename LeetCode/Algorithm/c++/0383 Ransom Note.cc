class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> m;
        m.fill(0);
        for (const char &c : magazine) {
            ++m[c - 'a']; 
        }
        for (const char &c : ransomNote) {
            --m[c - 'a'];
            if (m[c - 'a'] < 0) return false;
        }
        return true;
    }
};