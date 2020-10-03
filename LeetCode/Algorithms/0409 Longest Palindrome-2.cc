class Solution {
public:
    static int longestPalindrome(string s) {
        array<int, 128> count;
        count.fill(0);
        for (char &c : s) {
            ++count[c];
        }
        int ans = 0;
        for (int v: count) {
            ans += v/2 * 2;
            if (ans % 2 == 0 && v % 2 == 1)
                ans++;
        }
        return ans;
    }
};