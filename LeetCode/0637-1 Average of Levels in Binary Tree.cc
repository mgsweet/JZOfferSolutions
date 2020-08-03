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
    typedef pair<TreeNode*, int> NodeWithLevel;
    queue<NodeWithLevel> bfs;
    double sum = 0;
    int node_count = 0;
    int pre_level = 0;
    bfs.push(NodeWithLevel(root, 0));
    while (!bfs.empty()) {
      NodeWithLevel top = bfs.front();
      bfs.pop();
      if (top.second > pre_level) {
        res.push_back(sum / node_count);
        sum = 0;
        node_count = 0;
        pre_level = top.second;
      }
      sum += top.first->val;
      ++node_count;
      if (top.first->left) {
        bfs.push(NodeWithLevel (top.first->left, top.second + 1));
      }
      if (top.first->right) {
        bfs.push(NodeWithLevel (top.first->right, top.second + 1));
      }
    }
    res.push_back(sum / node_count);
    return res;
  }
};