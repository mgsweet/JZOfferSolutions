class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 计算两个数之和
   * @param s string字符串 表示第一个整数
   * @param t string字符串 表示第二个整数
   * @return string字符串
   */
  string solve(string s, string t) {
    // write code here
    int carry = 0;
    int i = s.size() - 1;
    int j = t.size() - 1;
    string &res = s.size() > t.size() ? s : t;
    int k = res.size() - 1;
    int t1, t2, tmp;
    while (carry != 0 || i >=0 || j >= 0) {
      tmp = carry;
      carry = 0;
      t1 = t2 = 0;
      if (i >=0) t1 = s[i--] - '0';
      if (j >= 0) t2 = t[j--] - '0';
      tmp += t1 + t2;
      if (tmp >= 10) {
        carry = 1;
        tmp %= 10;
      }
      if (k >= 0) {
        res[k--] = tmp + '0';
      } else {
        res = res.insert(0, 1, char(tmp + '0'));
      }
    }
    return res;
  }
};