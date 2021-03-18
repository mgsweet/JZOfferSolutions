class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() <= 1) return vector<Interval>(intervals.begin(), intervals.end());
    vector<int> start_arr;
    vector<int> end_arr;
    for (auto const & interval: intervals) {
      start_arr.emplace_back(interval.start);
      end_arr.emplace_back(interval.end);
    }
    sort(start_arr.begin(), start_arr.end());
    sort(end_arr.begin(), end_arr.end());
    vector<Interval> res;
    int cur_start = start_arr[0];
    int cur_end = end_arr[0];
    for (int i = 1; i < start_arr.size(); ++i) {
      if (start_arr[i] <= cur_end) {
        cur_end = end_arr[i];
      } else {
        res.emplace_back(cur_start, cur_end);
        cur_start = start_arr[i];
        cur_end = end_arr[i];
      }
    }
    res.emplace_back(cur_start, cur_end);
    return res;
  }
};