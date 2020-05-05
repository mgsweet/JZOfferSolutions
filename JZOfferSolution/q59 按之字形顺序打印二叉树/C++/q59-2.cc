class Solution {
public:
  static vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> > res;
    if (pRoot == nullptr) return res;
    stack<TreeNode*> myStack[2];
    int current = 0;
    myStack[0].push(pRoot);
    TreeNode *tmp, *next1, *next2;
    vector<int> ans;
    while(!myStack[current].empty()) {
      ans.clear();
      while(!myStack[current].empty()) {
        tmp = myStack[current].top();
        ans.push_back(tmp->val);
        next1 = current == 0 ? tmp->left : tmp->right;
        next2 = current == 0 ? tmp->right : tmp->left;
        if (next1) {
          myStack[current ^ 1].push(next1);
        }
        if (next2) {
          myStack[current ^ 1].push(next2);
        }
        myStack[current].pop();
      }
      if (!ans.empty()) res.push_back(ans);
      current ^= 1;
    }
    return res;
  }
};