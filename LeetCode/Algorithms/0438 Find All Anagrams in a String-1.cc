class Solution {
public:
  static vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if (s.empty() || p.empty() || p.size() > s.size())
      return ans;
    multiset<char> init_set;
    for (char c: p) {
      init_set.insert(c);
    }
    multiset<char> tmp = init_set;
    int slow = 0, fast = 0;
    while (fast != s.size()) {
      if (tmp.count(s[fast]) == 0) {
        while (s[slow] != s[fast]) {
          tmp.insert(s[slow++]);
        }
        ++slow;
        if (slow == fast) {
          tmp = init_set;
          auto iter = tmp.find(s[fast]);
          if (iter != tmp.end())
            tmp.erase(iter);
        }
      } else {
        tmp.erase(tmp.find(s[fast]));
        if (tmp.empty()) {
          ans.push_back(slow);
          tmp.insert(s[slow]);
          slow += 1;
        }
      }
      ++fast;
    }
    return ans;
  }
};