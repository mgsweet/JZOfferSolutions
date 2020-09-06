class Solution {
private:
  TreeNode* assist(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *lhs = nullptr, *rhs = nullptr;
    if (root->left) lhs = assist(root->left);
    if (root->right) rhs = assist(root->right);
    if (lhs && rhs) {
      lhs->right = root->right;
      root->right = root->left;
      root->left = nullptr;
      return rhs;
    } else if (lhs && !rhs) {
      root->right = root->left;
      root->left = nullptr;
      return lhs;
    } else if (!lhs && rhs) {
      return rhs;
    } else {
      return root;
    }
  }
public:
  void flatten(TreeNode *root) {
    assist(root);
  }
};