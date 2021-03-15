#include <unordered_map>

class Solution {
public:
  static vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> myHash;
    for (int i = 0; i < numbers.size(); ++i) {
      if (myHash.find(numbers[i]) != myHash.end()) {
        return vector<int>{myHash.find(numbers[i])->second + 1, i + 1};
      }
      if (target < INT_MIN + numbers[i]) continue;
      if (target - numbers[i] >= 0) myHash[target - numbers[i]] = i;
    }
    return vector<int>{-1, -1};
  }
};
