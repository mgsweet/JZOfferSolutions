class Solution {
private:
  static void iterateTree(TreeNode *root, int add, int target, int &count) {
      if (root == nullptr) return;
      root->val += add;
      if (root->val == target) ++count;
      iterateTree(root->left, root->val, target, count);
      iterateTree(root->right, root->val, target, count);
  }
  static void iterateTree2(TreeNode *root, int sub, int target, int &count) {
    if (root == nullptr) return;
    root->val -= sub;
    if (root->val == target) ++count;
    iterateTree2(root->left, sub, target, count);
    iterateTree2(root->right, sub, target, count);
  }
public:
  static int pathSum(TreeNode *root, int sum) {
    if (root == nullptr) return 0;
    int count = 0;
    iterateTree(root, 0, sum, count);
    queue<TreeNode*> bfs;
    bfs.push(root);
    while(!bfs.empty()) {
      TreeNode* p = bfs.front();
      iterateTree2(p->left, p->val, sum, count);
      iterateTree2(p->right, p->val, sum, count);
      if (p->left) bfs.push(p->left);
      if (p->right) bfs.push(p->right);
      bfs.pop();
    }
    return count;
  }
};