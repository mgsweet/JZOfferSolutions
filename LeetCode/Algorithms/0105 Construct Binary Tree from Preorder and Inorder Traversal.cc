class Solution {
private:
  static TreeNode *
  buildTreeAssist(vector<int> &preorder, vector<int> &inorder, int pre_start, int pre_end, int in_start, int in_end) {
    TreeNode *new_node = new TreeNode(preorder[pre_start]);
    if (pre_start == pre_end) return new_node;
    int mid = in_start;
    while (mid <= in_end && inorder[mid] != preorder[pre_start]) {
      ++mid;
    }
    int left_length = mid - in_start;
    int right_length = in_end - mid;
    if (left_length > 0)
      new_node->left = buildTreeAssist(preorder, inorder, pre_start + 1, pre_start + left_length, in_start, mid - 1);
    if (right_length > 0)
      new_node->right = buildTreeAssist(preorder, inorder, pre_start + left_length + 1, pre_end, mid + 1, in_end);
    return new_node;
  }

public:
  static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || preorder.size() != inorder.size()) return nullptr;
    return buildTreeAssist(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  }
};