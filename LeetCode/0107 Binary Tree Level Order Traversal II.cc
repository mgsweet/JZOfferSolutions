class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    queue<TreeNode *> my_queue;
    if (root == nullptr)
      return res;
    my_queue.push(root);
    // Use nullptr to separate different depth node.
    my_queue.push(nullptr);
    vector<int> vec;
    while (my_queue.size()) {
      TreeNode *frontNode = my_queue.front();
      my_queue.pop();
      // When all the children of the current level have been add to the queue
      if (!frontNode) {
        if (vec.size())
          res.push_back(vec);
        vec.clear();
        if (my_queue.size()) my_queue.push(nullptr);
      } else {
        vec.push_back(frontNode->val);
        if (frontNode->left) my_queue.push(frontNode->left);
        if (frontNode->right) my_queue.push(frontNode->right);
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};