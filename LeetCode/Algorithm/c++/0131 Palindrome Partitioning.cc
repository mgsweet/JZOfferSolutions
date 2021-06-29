class Solution {
public:
  static void assist(string &s, vector<vector<string>> &ans, vector<string> &tmp, const vector<vector<int>> &match, int index) {
    if (index >= s.size()) {
      ans.push_back(tmp);
      return;
    }
    for (int i = 0; i < match[index].size(); ++i) {
      tmp.push_back(s.substr(index, match[index][i] - index + 1));
      assist(s, ans, tmp, match, match[index][i] + 1);
      tmp.pop_back();
    }
  }

  static vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<vector<int>> match(s.size(), vector<int>());
    vector<string> v_s(s.size(), "");
    int mid, r_s;
    string tmp_s;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        v_s[j].push_back(s[i]);
        mid = v_s[j].size() / 2;
        r_s = v_s[j].size() % 2 ? mid + 1 : mid;
        tmp_s = v_s[j].substr(r_s, mid);
        reverse(tmp_s.begin(), tmp_s.end());
        if (v_s[j].substr(0, mid) == tmp_s) match[j].push_back(i);
      }
    }
    vector<string> tmp;
    assist(s, ans, tmp, match, 0);
    return ans;
  }
};