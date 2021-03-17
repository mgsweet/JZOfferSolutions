#include <unordered_map>

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
      if (arr.empty()) return 0;
      unordered_map<int, int> my_hash;
      int start = 0;
      int max_sub_len = 1;
      for (int i = 0; i < arr.size(); ++i) {
        if (my_hash.find(arr[i]) != my_hash.end()) {
          max_sub_len = max(max_sub_len, i - start);
          start = max(start, my_hash[arr[i]] + 1);
        }
        my_hash[arr[i]] = i;
      }
      max_sub_len = max(max_sub_len, int(arr.size()) - start);
      return max_sub_len;
    }
};