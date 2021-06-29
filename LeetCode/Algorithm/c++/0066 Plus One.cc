class Solution {
public:
  static vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    if (digits.empty()) return ans;
    bool carry = true;
    for (int i = digits.size() - 1; i >= 0; --i) {
      if (!carry) {
        ans.push_back(digits[i]);
      } else {
        if (digits[i] == 9) {
          ans.push_back(0);
        } else {
          ans.push_back(digits[i] + 1);
          carry = false;
        }
      }
    }
    if (carry) {
      ans.push_back(1);
    }
    return vector<int>(ans.rbegin(), ans.rend());
  }
};