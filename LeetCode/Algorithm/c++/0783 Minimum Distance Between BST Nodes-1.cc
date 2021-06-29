class Solution {
public:
  void assist(TreeNode *root, int &minimum, int &current) {
    if (root->left) assist(root->left, minimum, current);
    if (current != INT_MIN) minimum = min(root->val - current, minimum);
    current = root->val;
    if (root->right) assist(root->right, minimum, current);
  }
  int minDiffInBST(TreeNode *root) {
    if (!root) return -1;
    int minimum = INT_MAX;
    int current = INT_MIN;
    assist(root, minimum, current);
    return minimum;
  }
};
