class Solution {
public:
    static vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int new_s = -1, new_e = -1;
        int i = 0;
        bool is_done = false;
        while (i < intervals.size()) {
            if (new_s == -1) {
                if (newInterval[0] <= intervals[i][0]) {
                    new_s = newInterval[0];
                } else if (newInterval[0] > intervals[i][0] && newInterval[0] <= intervals[i][1]) {
                    new_s = intervals[i][0];
                } else {
                    ans.push_back(intervals[i]);
                    ++i;
                }
            } else if (!is_done) {
                if (newInterval[1] < intervals[i][0]) {
                    ans.push_back({new_s, newInterval[1]});
                    is_done = true;
                } else if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                    ans.push_back({new_s, intervals[i][1]});
                    is_done = true;
                    ++i;
                } else {
                    ++i;
                }
            } else {
                ans.push_back(intervals[i++]);
            }
        }
        if (!is_done) {
          if (new_s == -1) ans.push_back(newInterval);
          else ans.push_back({new_s, newInterval[1]});
        }
        return ans;
    }
};