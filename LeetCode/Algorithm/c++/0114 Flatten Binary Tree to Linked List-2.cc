class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *p;
    while (root) {
      p = root;
      if (root->left) {
        p = root->left;
        while (p->right) {
          p = p->right;
        }
        p->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      root = root->right;
    }
  }
};