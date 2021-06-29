class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* lhs = lowestCommonAncestor(root->left, p, q);
    TreeNode* rhs = lowestCommonAncestor(root->right, p, q);
    return !lhs ? rhs : !rhs ? lhs : root;
  }
};