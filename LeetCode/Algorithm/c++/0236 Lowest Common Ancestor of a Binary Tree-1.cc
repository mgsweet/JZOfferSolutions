class Solution {
public:
  static void find_node(TreeNode *root, TreeNode *p, stack<TreeNode *> &st, bool &is_found) {
    if (!root) return;
    st.push(root);
    if (p == root) {
      is_found = true;
      return;
    }
    find_node(root->left, p, st, is_found);
    if (is_found) return;
    find_node(root->right, p, st, is_found);
    if (is_found) return;
    st.pop();
  }

  static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    stack<TreeNode *> sp;
    stack<TreeNode *> sq;
    bool is_found = false;
    find_node(root, p, sp, is_found);
    is_found = false;
    find_node(root, q, sq, is_found);
    stack<TreeNode *> *big_s = sp.size() > sq.size() ? &sp : &sq;
    stack<TreeNode *> *small_s = sp.size() > sq.size() ? &sq : &sp;
    while (big_s->size() > small_s->size()) {
      big_s->pop();
    }
    while (big_s->top() != small_s->top()) {
      big_s->pop();
      small_s->pop();
    }
    return big_s->top();
  }
};