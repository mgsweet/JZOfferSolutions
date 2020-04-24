/*
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
  }
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        int depth = 0;
        typedef pair<TreeNode*, int> NodeWithDepth;
        stack<NodeWithDepth> my_stack;
        if (pRoot != nullptr) my_stack.push(NodeWithDepth(pRoot, 1));
        while (!my_stack.empty()) {
            NodeWithDepth top = my_stack.top();
            my_stack.pop();
            depth = max(depth, top.second);
            if (top.first->left)
                my_stack.push(NodeWithDepth(top.first->left, top.second + 1));
            if (top.first->right)
                my_stack.push(NodeWithDepth(top.first->right, top.second + 1));
        }
        return depth;
    }
};
