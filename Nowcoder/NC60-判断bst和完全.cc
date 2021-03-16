class Solution {
public:
  /**
   *
   * @param root TreeNode类 the root
   * @return bool布尔型vector
   */
  static vector<bool> judgeIt(TreeNode* root) {
    if (!root) return vector<bool>{true, true};
    // Is complete?
    bool isCompleteTree = true;
    bool judging = false;
    queue<TreeNode*> bfs;
    bfs.push(root);
    while(!bfs.empty()) {
      if (bfs.front() == nullptr) {
        judging = true;
      } else {
        if (judging) {
          isCompleteTree = false;
          break;
        };
        bfs.push(bfs.front()->left);
        bfs.push(bfs.front()->right);
      }
      bfs.pop();
    }
    // Is bst
    bool isBinaryTree = true;
    AssistFuc(isBinaryTree, root);
    return vector<bool>{isBinaryTree, isCompleteTree};
  }
  static int AssistFuc(bool& isBinaryTree, TreeNode* node) {
    if (!isBinaryTree) return -1;
    if (node->left && node->val < AssistFuc(isBinaryTree, node->left)) {
      isBinaryTree = false;
      return -1;
    };
    if (!isBinaryTree) return -1;
    int max_right = node->val;
    if (node->right) max_right = AssistFuc(isBinaryTree, node->right);
    if (!isBinaryTree) return -1;
    if (node->val > max_right) {
      isBinaryTree = false;
      return -1;
    };
    return max_right;
  }
};