class Solution {
public:
  static vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() < 2) return intervals;
    vector<vector<int> > res;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2){ return v1[0] < v2[0]; });
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      if (res.back()[1] >= intervals[i][0]) (res.back()[1] = max(res.back()[1], intervals[i][1]));
      else res.push_back(intervals[i]);
    }
    return res;
  }
};