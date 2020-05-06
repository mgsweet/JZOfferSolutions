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
  static TreeNode* KthNode(TreeNode* pRoot, int k, int& current) {
    if (pRoot == nullptr) return nullptr;
    TreeNode* res = KthNode(pRoot->left, k, current);
    if (res) return res;
    ++current;
    if (k == current) {
      return pRoot;
    }
    res = KthNode(pRoot->right, k, current);
    if (res) return res;
    return nullptr;
  }

  static TreeNode* KthNode(TreeNode* pRoot, int k)
  {
    if (pRoot == nullptr || k <= 0) return nullptr;
    int current = 0;
    return KthNode(pRoot, k, current);
  }
};