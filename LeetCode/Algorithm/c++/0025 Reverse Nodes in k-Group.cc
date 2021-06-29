struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head) return nullptr;
    int node_num = 0;
    ListNode *p = head;
    while (p) {
      p = p->next;
      ++node_num;
    }
    auto dummy = make_shared<ListNode>();
    dummy->next = head;
    ListNode *pre = dummy.get(), *cur = head, *tmp;
    for (int i = 0; i < node_num / k; ++i) {
      for (int j = 0; j < k; ++j) {
        tmp = cur->next;
        cur->next = cur->next->next;
        tmp->next = pre->next;
        pre->next = tmp;
      }
      pre = cur;
      cur = cur->next;
    }
    return dummy->next;
  }
};