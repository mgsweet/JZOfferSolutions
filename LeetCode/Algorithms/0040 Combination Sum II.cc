class Solution {
private:
  void static FindAllCombination(vector<vector<int>> &ans, vector<int> &candidates, int target, int current_pos, vector<int> &current_vec) {
    for (int i = current_pos; i < candidates.size(); ++i) {
      current_vec.push_back(candidates[i]);
      if (target - candidates[i] == 0) {
        ans.push_back(current_vec);
      } else if (target - candidates[i] > 0) {
        FindAllCombination(ans, candidates, target - candidates[i], i + 1, current_vec);
      }
      current_vec.pop_back();
      while (i != candidates.size() - 1 && candidates[i + 1] == candidates[i]) {
        ++i;
      }
    }
  }
public:
  vector<vector<int>> static combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    if (candidates.empty()) return ans;
    sort(candidates.begin(), candidates.end());
    vector<int> current_vec;
    FindAllCombination(ans, candidates, target, 0, current_vec);
    return ans;
  }
};