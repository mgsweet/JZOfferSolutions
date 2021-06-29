class Solution {
public:
  static string toHex(int num) {
    if (num == 0) return "0";
    unsigned int u_num = num;
    string ans;
    int tmp;
    while (u_num) {
      tmp = u_num & 15;
      if (tmp < 10) {
        ans += to_string(tmp);
      } else {
        ans += char(tmp - 10 + 'a');
      }
      u_num >>= 4;
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
      if (ans[i] == '0') {
        ans.pop_back();
      } else {
        break;
      }
    }
    return string(ans.rbegin(), ans.rend());
  }
};