class Solution {
public:
  int minimum = INT_MAX, pre = -1;
  int minDiffInBST(TreeNode *root) {
    if (root->left) minDiffInBST(root->left);
    if (pre >= 0) minimum = min(minimum, root->val - pre);
    pre = root->val;
    if (root->right) minDiffInBST(root->right);
    return minimum;
  }
};