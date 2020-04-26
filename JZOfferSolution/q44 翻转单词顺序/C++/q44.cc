class Solution {
public:
    void ReverseSentence(string &str, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(str[i], str[j]);
        }
        return;
    }
    
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        ReverseSentence(str, 0, str.size() - 1);
        int start = 0, end = 0;
        while(start < str.size()) {
            if (end == str.size() || str[end] == ' ') {
                ReverseSentence(str, start, end - 1);
                start = end + 1;
            }
            ++end;
        }
        return str;
    }
};
