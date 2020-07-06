class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "false";
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string ans = "";
        int count = 0;
        char pre = '#';
        for (char ctr : s) {
            if (ctr < '0' || ctr > '9') {
                return "false";
            }
            if (pre == '#') {
                pre = ctr;
            } else if (pre != ctr) {
                ans += to_string(count) + pre;
                count = 0;
                pre = ctr;
            }
            ++count;
        }
        if (pre != '#') {
            ans += to_string(count) + pre;
        }
        return ans;
    }
};