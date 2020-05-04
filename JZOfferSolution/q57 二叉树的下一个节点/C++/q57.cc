/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
  TreeLinkNode* GetNext(TreeLinkNode* p_node)
  {
    if (p_node == nullptr) return nullptr;
    if (p_node->right) {
      p_node = p_node->right;
      while (p_node->left) {
        p_node = p_node->left;
      }
      return p_node;
    } else {
      while (p_node->next && p_node->next->right == p_node) {
        p_node = p_node->next;
      }
      return p_node->next;
    }
  }
};
