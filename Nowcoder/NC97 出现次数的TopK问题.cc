#include <unordered_map>

class Solution {
public:
  /**
   * return topK string
   * @param strings string字符串vector strings
   * @param k int整型 the k
   * @return string字符串vector<vector<>>
   */
  vector<vector<string> > topKstrings(vector<string>& strings, int k) {
    vector<vector<string> > res;
    if (k <= 0) return res;
    unordered_map<string, int> count;
    for (auto &s: strings) {
      ++count[s];
    }
    typedef pair<int, string> IS;
    auto cmp = [](const IS &l, const IS &r) -> bool {
      if (l.first != r.first) {
        return l.first < r.first;
      } else {
        return l.second > r.second;
      }
    };
    multiset<IS, decltype(cmp)> red_black(cmp);
    for (auto &p: count) {
      red_black.insert(IS(p.second, p.first));
      if (red_black.size() > k) {
        red_black.erase(red_black.begin());
      }
    }
    for (auto iter = red_black.rbegin(); iter != red_black.rend(); ++iter) {
      res.push_back(vector<string>{iter->second, to_string(iter->first)});
    }
    return res;
  }
};