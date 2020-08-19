class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    if (A.empty()) return 0;
    unordered_map<int, int> my_hashmap;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < B.size(); ++j) {
        my_hashmap[A[i] + B[j]]++;
      }
    }
    int ans = 0;
    for (int i = 0; i < C.size(); ++i) {
      for (int j = 0; j < D.size(); ++j) {
        if (my_hashmap.find(- C[i] - D[j]) != my_hashmap.end()) {
          ans += my_hashmap[- C[i] - D[j]];
        }
      }
    }
    return ans;
  }
};