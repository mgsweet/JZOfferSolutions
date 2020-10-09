class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> ans;
    unordered_map<string, int> m;
    for (int i = 0; i < list1.size(); ++i) {
      if (m.find(list1[i]) == m.end()) m[list1[i]] = i;
    }
    int min_sum = INT_MAX;
    for (int i = 0; i < list2.size(); ++i) {
      if (m.find(list2[i]) != m.end() && m[list2[i]] + i <= min_sum) {
        if (m[list2[i]] + i < min_sum) {
          ans.clear();
        }
        ans.push_back(list2[i]);
      }
    }
    return ans;
  }
};