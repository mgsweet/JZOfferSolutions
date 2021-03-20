class Solution {
public:
  ListNode *ReverseList(ListNode *p_head) {
    if (!p_head) return p_head;
    ListNode *dummy = new ListNode(0);
    dummy->next = p_head;
    ListNode *p_node = p_head, *p_tmp;
    while (p_node->next) {
       p_tmp = p_node->next;
       p_node->next = p_node->next->next;
       p_tmp->next = dummy->next;
       dummy->next = p_tmp;
    }
    p_head = dummy->next;
    delete dummy;
    return p_head;
  }
};