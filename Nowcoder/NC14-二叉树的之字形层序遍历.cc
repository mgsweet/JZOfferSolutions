/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    vector<int> tmp;
    bool isLeft2Right = true;
    if (!root) return res;
    queue<TreeNode *> bfs;
    bfs.push(root);
    bfs.push(nullptr);
    while (!bfs.empty()) {
      if (bfs.front() == nullptr) {
        if (bfs.size() > 1) bfs.push(nullptr);
        if (isLeft2Right) res.push_back(tmp);
        else res.push_back(vector<int>(tmp.rbegin(), tmp.rend()));
        isLeft2Right = !isLeft2Right;
        tmp.clear();
      } else {
        TreeNode *frontNode = bfs.front();
        tmp.push_back(frontNode->val);
        if (frontNode->left) bfs.push(frontNode->left);
        if (frontNode->right) bfs.push(frontNode->right);
      }
      bfs.pop();
    }
    return res;
  }
};