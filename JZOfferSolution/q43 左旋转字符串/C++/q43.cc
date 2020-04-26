class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty() || n < 1) {
            return str;
        }
        
        int len = str.size();
        int realMove = n % len;
        
        string subStr1 = str.substr(0, realMove);
        string subStr2 = str.substr(realMove);
        
        return subStr2.append(subStr1);
    }
};
