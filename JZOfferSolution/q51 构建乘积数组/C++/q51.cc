class Solution {
public:
  vector<int> static multiply(const vector<int>& A) {
    vector<int> ans(A);
    int vec_size = A.size();
    if (A.size() < 2)
      return ans;
    vector<int> forward_multi_vec(A), backward_multi_vec(A);
    for (int i = 1; i < vec_size; ++i) {
      forward_multi_vec[i] = forward_multi_vec[i - 1] * A[i];
      backward_multi_vec[vec_size - 1 - i]
        = backward_multi_vec[vec_size - i] * A[vec_size - 1 - i];
    }
    ans[0] = backward_multi_vec[1];
    ans[vec_size - 1] = forward_multi_vec[vec_size - 2];
    for (int i = 1; i < vec_size - 1; ++i) {
      ans[i] = forward_multi_vec[i - 1] * backward_multi_vec[i + 1];
    }
    return ans;
  }
};
