class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nums1_hash;
    unordered_map<int, int> nums2_hash;
    for (int i = 0; i < nums1.size(); ++i) {
      ++nums1_hash[nums1[i]];
    }
    for (int i = 0; i < nums2.size(); ++i) {
      ++nums2_hash[nums2[i]];
    }
    vector<int> ans;
    for (auto iter = nums1_hash.begin(); iter != nums1_hash.end(); ++iter) {
      if (nums2_hash[iter->first] != 0) {
        for (int j = 0; j < min(nums1_hash[iter->first], nums2_hash[iter->first]); ++j) {
          ans.push_back(iter->first);
        }
      }
    }
    return ans;
  }
};