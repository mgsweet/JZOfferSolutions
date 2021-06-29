class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> my_queue;
    my_queue.push(root);
    bool left2right = true;
    int index;
    vector<int> tmp;
    while (!my_queue.empty()) {
      tmp = vector<int>(my_queue.size());
      for (int i = 0; i < tmp.size(); ++i) {
        index = left2right ? i : tmp.size() - 1 - i;
        tmp[index] = my_queue.front()->val;
        if (my_queue.front()->left) my_queue.push(my_queue.front()->left);
        if (my_queue.front()->right) my_queue.push(my_queue.front()->right);
        my_queue.pop();
      }
      left2right = !left2right;
      res.push_back(tmp);
    }
    return res;
  }
};