class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping;
        unordered_map<char, bool> isused;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (mapping.find(s[i]) == mapping.end() 
                && isused.find(t[i]) == isused.end()) {
                mapping[s[i]] = t[i];
                isused[t[i]] = true;
            } else if (mapping[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};