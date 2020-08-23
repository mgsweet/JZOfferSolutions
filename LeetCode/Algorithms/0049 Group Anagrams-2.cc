class Solution {
public:
  static vector<vector<string>> groupAnagrams(vector<string>& strs) {
    array<int, 26> count_char;
    unordered_map<string, vector<string>> ht;
    for (int i = 0; i < strs.size(); ++i) {
      count_char.fill(0);
      for (int j = 0; j < strs[i].size(); ++j) {
        ++count_char[strs[i][j] - 'a'];
      }
      // create mask string
      string mask;
      for (int j = 0; j < 26; ++j) {
        mask += to_string(count_char[j]) + '#';
      }
      ht[mask].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto &p: ht) {
      ans.push_back(p.second);
    }
    return ans;
  }
};