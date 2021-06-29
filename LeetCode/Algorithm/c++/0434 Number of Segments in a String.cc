class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool word_appear = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') word_appear = true;
            else {
                if (word_appear) {
                    word_appear = false;
                    ++count;
                }
            }
        }
        if (word_appear) ++count;
        return count;
    } 
};