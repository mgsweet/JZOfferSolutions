#include <unordered_set>

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
      if (arr.empty()) return 0;
      unordered_set<int> my_set;
      int max_sub_len = 1;
      int slow = 0, fast = 0;
      while (fast < arr.size()) {
        if (my_set.find(arr[fast]) != my_set.end()) {
          my_set.erase(arr[slow++]);
        } else {
          my_set.insert(arr[fast++]);
          max_sub_len = max(max_sub_len, (int)my_set.size());
        }
      }
      return max_sub_len;
    }
};