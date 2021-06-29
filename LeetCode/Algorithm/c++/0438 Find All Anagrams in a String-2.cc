class Solution {
public:
  static vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if (s.empty() || p.empty() || p.size() > s.size())
      return ans;
    array<int, 26> s_arr, p_arr;
    for (int i = 0; i < p.size(); ++i) {
      ++s_arr[s[i] - 'a'];
      ++p_arr[p[i] - 'a'];
    }
    if (s_arr == p_arr) ans.push_back(0);
    for (int i = p.size(); i < s.size(); ++i) {
      ++s_arr[s[i] - 'a'];
      --s_arr[s[i - p.size()] - 'a'];
      if (s_arr == p_arr) ans.push_back(i - p.size() + 1);
    }
    return ans;
  }
};