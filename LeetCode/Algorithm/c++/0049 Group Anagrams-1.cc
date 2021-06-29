class Solution {
public:
  static vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string> tmpStrs = strs;
    for (int i = 0; i < tmpStrs.size(); ++i) {
      sort(tmpStrs[i].begin(), tmpStrs[i].end());
    }
    unordered_map<string, vector<string>> ht;
    for (int i = 0; i < strs.size(); ++i) {
      ht[tmpStrs[i]].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto &iter: ht) {
      ans.push_back(iter.second);
    }
    return ans;
  }
};