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
  vector<vector<int>> static levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    typedef pair<int, TreeNode*> MyPair;
    queue<MyPair> my_queue;
    my_queue.push(MyPair(0, root));
    vector<int> tmp;
    int pre_level = 0;
    while (!my_queue.empty()) {
      MyPair top = my_queue.front();
      my_queue.pop();
      if (top.first > pre_level) {
        pre_level = top.first;
        ans.push_back(tmp);
        tmp.clear();
      }
      tmp.push_back(top.second->val);
      if (top.second->left) my_queue.push(MyPair(top.first + 1, top.second->left));
      if (top.second->right) my_queue.push(MyPair(top.first + 1, top.second->right));
    }
    ans.push_back(tmp);
    return ans;
  }
};