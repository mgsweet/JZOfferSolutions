class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> count(58, 0);
        for (char c : str) {
            count[int(c - 'A')]++;
        }
        for (int i = 0; i < str.size(); i++) {
            if (count[int(str[i] - 'A')] == 1) {
                return i;
            }
        }
        return -1;
    }
};
