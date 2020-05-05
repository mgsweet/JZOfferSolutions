/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
  bool isSymetrical(TreeNode *p1_root, TreeNode *p2_root) {
    if (p1_root == nullptr && p2_root == nullptr) return true;
    if (p1_root == nullptr || p2_root == nullptr) return false;
    if (p1_root->val != p2_root->val) return false;
    return isSymetrical(p1_root->left, p2_root->right) && 
            isSymetrical(p1_root->right, p2_root->left);
  }
  
  bool isSymmetrical(TreeNode *p_root)
  {
    if (p_root == nullptr) return true;
    return isSymetrical(p_root->left, p_root->right);
  }
};