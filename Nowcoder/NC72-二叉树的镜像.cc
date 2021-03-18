class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
      if (!pRoot) return nullptr;
      TreeNode* tmp = pRoot->left;
      pRoot->left = pRoot->right;
      pRoot->right = tmp;
      Mirror(pRoot->left);
      Mirror(pRoot->right);
      return pRoot;
    }
};