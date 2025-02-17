class Solution {
public:
  static vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.size() < k) return vector<int>();
    sort(input.begin(), input.end(), less<int>());
    return vector<int>(input.begin(), input.begin() + k);
  }
};