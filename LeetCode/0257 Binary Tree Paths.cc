class Solution {
private:
  void IterateTreeAndFindPaths(TreeNode *root, vector<string> &ans, string &current) {
    if (root == nullptr) return;
    string tmp = current;
    current = current == "" ? to_string(root->val) : current + "->" + to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      ans.push_back(current);
    }
    if (root->left) {
      IterateTreeAndFindPaths(root->left, ans, current);
    }
    if (root->right) {
      IterateTreeAndFindPaths(root->right, ans, current);
    }
    current = tmp;
  }
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    string current;
    vector<string> ans;
    IterateTreeAndFindPaths(root, ans, current);
    return ans;
  }
};