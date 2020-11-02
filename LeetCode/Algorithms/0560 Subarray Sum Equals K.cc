// Approach 3: Without Space

// class Solution {
// public:
//   static int subarraySum(vector<int>& nums, int k) {
//     if (nums.empty()) return 0;
//     int sum = 0, count = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//       sum = 0;
//       for (int j = i; j < nums.size(); ++j) {
//         sum += nums[j];
//         if (sum == k) {
//           ++count;
//         }
//       }
//     }
//     return count;
//   }
// };

// Approach 4: Using Hashmap
class Solution {
public:
  static int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> my_map;
    int count = 0, sum = 0;
    ++my_map[0];
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      count += my_map[sum - k];
      ++my_map[sum];
    }
    return count;
  }
};