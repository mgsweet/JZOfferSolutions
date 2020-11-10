class Solution {
public:
  int res = INT_MAX, pre = INT_MIN;
  int getMinimumDifference(TreeNode* root) {
    if (root->left) getMinimumDifference(root->left);
    if (pre != INT_MIN) res = min(root->val - pre, res);
    pre = root->val;
    if (root->right) getMinimumDifference(root->right);
    return res;
  }
};