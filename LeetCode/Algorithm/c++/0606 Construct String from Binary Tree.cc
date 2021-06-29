/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void assist(TreeNode *root, string &ans) {
    if (!root) return;
    ans += to_string(root->val);
    if (root->left) {
      ans.push_back('(');
      assist(root->left, ans);
      ans.push_back(')');
    }
    if (root->right) {
      if (!root->left) ans += "()";
      ans.push_back('(');
      assist(root->right, ans);
      ans.push_back(')');
    }
  }
  string tree2str(TreeNode *t) {
    string ans;
    assist(t, ans);
    return ans;
  }
};