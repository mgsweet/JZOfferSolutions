class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> my_hash;
    for (auto num: nums) {
      ++my_hash[num];
      if (my_hash[num] == 3) {
        my_hash.erase(my_hash.find(num));
      }
    }
    return my_hash.begin()->first;
  }
};