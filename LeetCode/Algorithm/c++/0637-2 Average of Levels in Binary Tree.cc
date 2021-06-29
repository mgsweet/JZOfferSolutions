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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (root == nullptr) return res;
    queue<TreeNode*> dfs;
    dfs.push(root);
    double sum;
    while (!dfs.empty()) {
      sum = 0;
      int q_size = dfs.size();
      for (int i = 0; i < q_size; ++i) {
        TreeNode* top = dfs.front();
        dfs.pop();
        if (top->left) dfs.push(top->left);
        if (top->right) dfs.push(top->right);
        sum += top->val;
      }
      res.push_back(sum / q_size);
    }
    return res;
  }
};
