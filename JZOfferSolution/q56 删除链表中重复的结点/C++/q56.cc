/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
  static ListNode* deleteDuplication(ListNode* p_head)
  {
    ListNode *p_node = p_head;
    ListNode *p_next = p_node;
    ListNode *ans_head = nullptr, *ans_node = nullptr;
    bool skip = false;
    while (p_node != nullptr) {
      p_next = p_next->next;
      if (p_next != nullptr && p_next->val == p_node->val) {
        skip = true;
      } else {
        if (!skip) {
          if (ans_head == nullptr) {
            ans_head = p_node;
            ans_node = ans_head;
          } else {
            ans_node->next = p_node;
            ans_node = ans_node->next;
          }
        }
        p_node = p_next;
        skip = false;
      }
    }
    if (ans_node) {
      ans_node->next = nullptr;
    }
    return ans_head;
  }
};
