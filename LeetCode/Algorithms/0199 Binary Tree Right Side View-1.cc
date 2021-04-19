class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> bfs;
    vector<int> ans;
    if (root) {
        bfs.push(root);
        bfs.push(nullptr);
    }
    TreeNode* top_node;
    while (!bfs.empty()) {
      top_node = bfs.front();
      bfs.pop();
      if (top_node->left) bfs.push(top_node->left);
      if (top_node->right) bfs.push(top_node->right);
      if (bfs.front() == nullptr) {
        ans.push_back(top_node->val);
        bfs.pop();
        if (!bfs.empty())
          bfs.push(nullptr);
      }
    }
    return ans;
  }
};