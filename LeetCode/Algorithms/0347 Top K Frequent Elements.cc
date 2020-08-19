class Solution {
public:
  static vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hashtable;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      ++hashtable[nums[i]];
    }
    typedef pair<int, int> Mypair;
    auto cmp = [](const Mypair &p1, const Mypair &p2) {return p1.second > p2.second;};
    priority_queue<Mypair , vector<Mypair>, decltype(cmp)> my_queue(cmp);
    for (auto iter = hashtable.begin(); iter != hashtable.end(); ++iter) {
      if (my_queue.size() < k) {
        my_queue.push(*iter);
      } else if (my_queue.size() == k && my_queue.top().second < iter->second) {
        my_queue.pop();
        my_queue.push(*iter);
      }
    }
    while (!my_queue.empty()) {
      ans.push_back(my_queue.top().first);
      my_queue.pop();
    }
    return ans;
  }